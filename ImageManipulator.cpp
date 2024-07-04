#include "ImageManipulator.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @file ImageManipulator.cpp
 * @brief Implementation of the Image class for loading, saving, and manipulating images in the PPM format.
 * 
 * This project is created and maintained by Yash Dhone.
 */

// Constructors

/**
 * @brief Default constructor that creates an empty image.
 */
Image::Image() : width(0), height(0) {}

/**
 * @brief Constructor that creates an image with the specified width and height.
 * @param width The width of the image.
 * @param height The height of the image.
 */
Image::Image(int width, int height) : width(width), height(height) {
    pixels.resize(height, std::vector<std::array<int, 3>>(width));
}

// Load and save functions

/**
 * @brief Loads an image from a file.
 * @param filename The name of the file to load the image from.
 * @return True if the image was loaded successfully, false otherwise.
 */
bool Image::load(const std::string& filename) {
    return readPPM(filename);
}

/**
 * @brief Saves the image to a file.
 * @param filename The name of the file to save the image to.
 * @return True if the image was saved successfully, false otherwise.
 */
bool Image::save(const std::string& filename) const {
    return writePPM(filename);
}

// Manipulation functions

/**
 * @brief Converts the image to grayscale.
 */
void Image::toGrayscale() {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            int gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            pixel[0] = pixel[1] = pixel[2] = gray;
        }
    }
}

/**
 * @brief Inverts the colors of the image.
 */
void Image::invertColors() {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }
}

/**
 * @brief Adjusts the brightness of the image.
 * @param value The value to adjust the brightness by. Can be negative or positive.
 */
void Image::adjustBrightness(int value) {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel[0] = std::max(0, std::min(255, pixel[0] + value));
            pixel[1] = std::max(0, std::min(255, pixel[1] + value));
            pixel[2] = std::max(0, std::min(255, pixel[2] + value));
        }
    }
}

/**
 * @brief Inverts the image laterally (left to right).
 * @param image The image to invert.
 */
void invertLaterally(Image& image) {
    auto& pixels = image.getPixels();
    int width = image.getWidth();
    int height = image.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width / 2; ++x) {
            std::swap(pixels[y][x], pixels[y][width - 1 - x]);
        }
    }
}


/**
 * @brief Rotates the image by a specified angle.
 * @param angle The angle to rotate the image by (90, 180, or 270 degrees).
 */
void Image::rotate(int angle) {
    if (angle == 90) {
        rotate90();
    } else if (angle == 180) {
        rotate180();
    } else if (angle == 270) {
        rotate270();
    } else {
        std::cerr << "Invalid rotation angle. Only 90, 180, and 270 are supported." << std::endl;
    }
}

 /**
     * @brief Returns the Width of the image.
     */
    int Image::getWidth(){return width;}

     /**
     * @brief Returns the Height of the image.
     */
    int Image::getHeight(){return height;}

// Accessor for pixels

/**
 * @brief Accessor for the pixel data.
 * @return A reference to the pixel data.
 */
std::vector<std::vector<std::array<int, 3>>>& Image::getPixels() {
    return pixels;
}

// Helper functions

/**
 * @brief Rotates the image by 90 degrees clockwise.
 */
void Image::rotate90() {
    std::vector<std::vector<std::array<int, 3>>> rotatedPixels(height, std::vector<std::array<int, 3>>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            rotatedPixels[x][height - 1 - y] = pixels[y][x];
        }
    }
    pixels = std::move(rotatedPixels);
    std::swap(width, height);
}

/**
 * @brief Rotates the image by 180 degrees.
 */
void Image::rotate180() {
    rotate90();
    rotate90();
}

/**
 * @brief Rotates the image by 270 degrees clockwise.
 */
void Image::rotate270() {
    rotate180();
    rotate90();
}

// PPM specific functions

/**
 * @brief Reads an image from a PPM file.
 * @param filename The name of the PPM file to read from.
 * @return True if the image was read successfully, false otherwise.
 */
bool Image::readPPM(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string header;
    inputFile >> header;
    if (header != "P3") {
        std::cerr << "Unsupported PPM format: " << header << std::endl;
        return false;
    }

    inputFile >> width >> height;
    int maxColorValue;
    inputFile >> maxColorValue;

    pixels.resize(height, std::vector<std::array<int, 3>>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            inputFile >> pixels[y][x][0] >> pixels[y][x][1] >> pixels[y][x][2];
        }
    }

    return true;
}

/**
 * @brief Writes the image to a PPM file.
 * @param filename The name of the PPM file to write to.
 * @return True if the image was written successfully, false otherwise.
 */
bool Image::writePPM(const std::string& filename) const {
    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    outputFile << "P3\n" << width << " " << height << "\n255\n";
    for (const auto& row : pixels) {
        for (const auto& pixel : row) {
            outputFile << pixel[0] << " " << pixel[1] << " " << pixel[2] << " ";
        }
        outputFile << "\n";
    }

    return true;
}
