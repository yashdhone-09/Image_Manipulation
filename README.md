# Image Manipulator

## Overview
Welcome to the Image Manipulator project! This tool is developed in C++ and is designed to work with PPM (Portable Pixmap) image files. It provides various functionalities to manipulate images such as converting to grayscale, inverting colors, adjusting brightness, and rotating images.

## Why This Project is Useful
Image manipulation is a fundamental task in many fields including computer graphics, digital photography, and image processing. This project provides a simple yet powerful tool to perform basic image manipulations on PPM files. It is a great learning resource for those looking to understand image processing algorithms and C++ programming.

## Features
- **Load and save images**: Support for PPM format
- **Grayscale conversion**: Convert color images to grayscale
- **Image inversion**: Invert the colors of an image
- **Brightness adjustment**: Increase or decrease the brightness of an image
- **Image rotation**: Rotate images by 90, 180, or 270 degrees

## Getting Started

### Prerequisites
Before you begin, ensure you have the following:
- A C++ compiler (supporting C++11 or higher)
- CMake (optional, for building the project)
- Git (for cloning the repository)

### Installation
1. **Clone the repository**:
    ```sh
    git clone https://github.com/yashdhone-09/image-manipulator.git
    cd image-manipulator
    ```

2. **Build with CMake** (optional):
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Alternatively, compile manually**:
    ```sh
    g++ -std=c++11 -o image_manipulator main.cpp ImageManipulator.cpp
    ```

### Usage
To use the image manipulator, run the executable with the following syntax:

```sh
./image_manipulator <command> <input_file> <output_file>
For Example:
    ./image_manipulator grayscale images/color_image.ppm images/grayscale_image.ppm
    ./image_manipulator invert input.ppm output.ppm

