#include "ImageManipulator.hpp"
#include <iostream>

/**
 * @file main.cpp
 * @brief Demonstrates the usage of the Image class by creating and manipulating PPM images.
 * 
 * This project is created and maintained by Yash Dhone (yashdhone-09).
 */

/**
 * @brief Main function that creates and manipulates several PPM images.
 * 
 * This function creates an image, applies several manipulations to it, and saves the results as PPM files.
 * 
 * @return int Returns 0 if the program completes successfully.
 */
int main() {
    // Create an image with dimensions 100x100
    Image img(100, 100);

    // Fill the image with a gradient
    auto& pixels = img.getPixels();
    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 100; ++x) {
            pixels[y][x] = { static_cast<int>(x * 2.55), static_cast<int>(y * 2.55), 127 }; // A simple gradient
        }
    }

    // Save the original gradient image
    if (!img.save("gradient.ppm")) {
        std::cerr << "Failed to save gradient.ppm" << std::endl;
    }

    // Convert to grayscale and save
    img.toGrayscale();
    if (!img.save("gradient_grayscale.ppm")) {
        std::cerr << "Failed to save gradient_grayscale.ppm" << std::endl;
    }

    // Invert colors and save
    img.invertColors();
    if (!img.save("gradient_inverted.ppm")) {
        std::cerr << "Failed to save gradient_inverted.ppm" << std::endl;
    }

    // Rotate by 90 degrees and save
    img.rotate(90);
    if (!img.save("gradient_rotated_90.ppm")) {
        std::cerr << "Failed to save gradient_rotated_90.ppm" << std::endl;
    }

    // Adjust brightness and save
    img.adjustBrightness(50);
    if (!img.save("gradient_brightened.ppm")) {
        std::cerr << "Failed to save gradient_brightened.ppm" << std::endl;
    }

    std::cout << "PPM images created successfully." << std::endl;
     Image apolloImage;
    if (!apolloImage.load("apollo.ppm")) {
        std::cerr << "Failed to load apollo.ppm" << std::endl;
        return 1;
    }

    Image landscapeImage;
    if (!landscapeImage.load("landscape.ppm")) {
        std::cerr << "Failed to load landscape.ppm" << std::endl;
        return 1;
    }

    // Invert images laterally
    invertLaterally(apolloImage);
    invertLaterally(landscapeImage);

    // Save modified images
    if (!apolloImage.save("apollo_inverted.ppm")) {
        std::cerr << "Failed to save apollo_inverted.ppm" << std::endl;
        return 1;
    }

    if (!landscapeImage.save("landscape_inverted.ppm")) {
        std::cerr << "Failed to save landscape_inverted.ppm" << std::endl;
        return 1;
    }

    std::cout << "Images inverted laterally and saved successfully." << std::endl;
    return 0;
    return 0;
}
