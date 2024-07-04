#include "ImageManipulator.hpp"
#include <iostream>

/**
 * @file main.cpp
 * @brief Loads two PPM images, inverts them laterally, and saves the modified images.
 * 
 * This project is created and maintained by Yash Dhone.
 */

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
 * @brief Main function that loads images, inverts them laterally, and saves the modified images.
 * 
 * @return int Returns 0 if the program completes successfully.
 */
int main() {
    // Load images
    Image apolloImage;
    if (!apolloImage.load("apollo.ppm")) {
        std::cerr << "Failed to load apollo.ppm" << std::endl;
        return 1;
    }

    Image monumentImage;
    if (!monumentImage.load("monument.ppm")) {
        std::cerr << "Failed to load monument.ppm" << std::endl;
        return 1;
    }

    // Invert images laterally
    invertLaterally(apolloImage);
    invertLaterally(monumentImage);

    // Save modified images
    if (!apolloImage.save("apollo_inverted.ppm")) {
        std::cerr << "Failed to save apollo_inverted.ppm" << std::endl;
        return 1;
    }

    if (!monumentImage.save("monument_inverted.ppm")) {
        std::cerr << "Failed to save monument_inverted.ppm" << std::endl;
        return 1;
    }

    std::cout << "Images inverted laterally and saved successfully." << std::endl;

    return 0;
}
