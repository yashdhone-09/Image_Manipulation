#ifndef IMAGE_MANIPULATOR_HPP
#define IMAGE_MANIPULATOR_HPP

#include <vector>
#include <array>
#include <string>

/**
 * @class Image
 * @brief A class for loading, saving, and manipulating images in the PPM format.
 * 
 * This project is created and maintained by Yash Dhone.
 */
class Image {
public:
    /**
     * @brief Default constructor that creates an empty image.
     */
    Image();

    /**
     * @brief Constructor that creates an image with the specified width and height.
     * @param width The width of the image.
     * @param height The height of the image.
     */
    Image(int width, int height);

    /**
     * @brief Loads an image from a file.
     * @param filename The name of the file to load the image from.
     * @return True if the image was loaded successfully, false otherwise.
     */
    bool load(const std::string& filename);

    /**
     * @brief Saves the image to a file.
     * @param filename The name of the file to save the image to.
     * @return True if the image was saved successfully, false otherwise.
     */
    bool save(const std::string& filename) const;

    /**
     * @brief Converts the image to grayscale.
     */
    void toGrayscale();

    /**
     * @brief Returns the Width of the image.
     */
    int getWidth();

     /**
     * @brief Returns the Height of the image.
     */
    int getHeight();

    /**
     * @brief Inverts the colors of the image.
     */

     
    
    void invertColors();

    /**
     * @brief Adjusts the brightness of the image.
     * @param value The value to adjust the brightness by. Can be negative or positive.
     */
    void adjustBrightness(int value);

    /**
     * @brief Rotates the image by a specified angle.
     * @param angle The angle to rotate the image by (90, 180, or 270 degrees).
     */
    void rotate(int angle);

    /**
     * @brief Accessor for the pixel data.
     * @return A reference to the pixel data.
     */
    std::vector<std::vector<std::array<int, 3>>>& getPixels();

private:
    int width; ///< The width of the image.
    int height; ///< The height of the image.
    std::vector<std::vector<std::array<int, 3>>> pixels; ///< The pixel data of the image.

    /**
     * @brief Rotates the image by 90 degrees clockwise.
     */
    void rotate90();

    /**
     * @brief Rotates the image by 180 degrees.
     */
    void rotate180();

    /**
     * @brief Rotates the image by 270 degrees clockwise.
     */
    void rotate270();

    /**
     * @brief Reads an image from a PPM file.
     * @param filename The name of the PPM file to read from.
     * @return True if the image was read successfully, false otherwise.
     */
    bool readPPM(const std::string& filename);

    /**
     * @brief Writes the image to a PPM file.
     * @param filename The name of the PPM file to write to.
     * @return True if the image was written successfully, false otherwise.
     */
    bool writePPM(const std::string& filename) const;
};
/**
     *@brief Invert Image Laterally
     */
    
    void invertLaterally(Image& image);

#endif // IMAGE_MANIPULATOR_HPP
