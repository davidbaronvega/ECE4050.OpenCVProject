#include "ImageManager.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Constructor and deconstructor of our ImageManager class:
ImageManager::ImageManager()
{
    // This object allows us to select and sort through the directory/vector of images.
    current_image_index = 0;

    // Initializing our new Mat object to an empty matrix for subsequent image modifications.
    modifiedImage = cv::Mat();
}
ImageManager::~ImageManager()
{
}

// Defining the created functions:

/* This 'load images' function below, which belongs to the class ImageManager, allows us to index and vectorize
the string of filepaths to access different images easily. */
void ImageManager::loadImages(const vector<string>& filepaths)
{
    for (const auto& filepath : filepaths)
    {
        Mat image = imread(filepath);
        if (image.empty())
        {
            cout << "No images were not found in the provided filepath." << endl;
            continue; // Skip to the next iteration
        }

        images.push_back(image); //This will add filepaths of images to our images vector, which we can reference to access all the images in the directory.
    }

    // Reset current image index after loading new images
    current_image_index = 0;
}

/* This 'display current image' function below, which belongs to the class ImageManager, allows us display the
currently indexed image using the imshow function available throught the OpenCV libraries. */
cv::Mat ImageManager::displayCurrentImage()
{
    if (images.empty())
    {
        cout << "No images loaded." << endl;
        return cv::Mat();  // Returns an empty matrix if there are no images
    }

    currentImage = images[current_image_index];
    modifiedImage = currentImage;

    // Return the current image
    return currentImage;
}

//Function to select next image in the images vector.
cv::Mat ImageManager::nextImage()
{
    if (images.empty())
    {
        cout << "No images loaded." << endl;
        return cv::Mat();  // Returns an empty matrix if there are no images
    }

    // Moving to the next image, wrapping around at the end using modulo of our vector size 
    current_image_index = (current_image_index + 1) % images.size();
    currentImage = images[current_image_index];
    modifiedImage = currentImage;

    // Return the new current image
    return currentImage;
}

//Function to select previous image in the images vector.
cv::Mat ImageManager::prevImage()
{
    if (images.empty())
    {
        cout << "No images loaded." << endl;
        return cv::Mat();  // Returns an empty matrix if there are no images
    }

    // Move to the previous image, wrapping around at the start using modulo of our vector size.
    current_image_index = (current_image_index - 1 + images.size()) % images.size();
    currentImage = images[current_image_index];
    modifiedImage = currentImage;

    // Return the new current image
    return currentImage;
}

//This function will increase the brightness of the currently displayed image.
cv::Mat ImageManager::increaseBrightness()
{
    // Increasing the brightness by adding a constant to every pixel, using ConvertTo OpenCV function:
    modifiedImage.convertTo(modifiedImage, -1, 1, 25); // increase brightness by 25

    // Return the modified image
    return modifiedImage;
}

//This function will decrease the brightness of the currently displayed image. Very similar to previous function.
cv::Mat ImageManager::decreaseBrightness()
{
    // Decreasing the brightness by subtracting a constant from every pixel:
    modifiedImage.convertTo(modifiedImage, -1, 1, -25);

    // Return the modified image
    return modifiedImage;
}

//This function will increase the contrast of the currently displayed image.
cv::Mat ImageManager::increaseContrast()
{
    // Increasing the contrast by scaling every pixel:
    modifiedImage.convertTo(modifiedImage, -1, 1.2, 0); // increase contrast by 20%

    // Return the modified image
    return modifiedImage;
}

//This function will decrease the contrast of the currently displayed image.
cv::Mat ImageManager::decreaseContrast()
{
    modifiedImage.convertTo(modifiedImage, -1, 0.8, 0); // decrease contrast by 20%

    // Return the modified image
    return modifiedImage;
}

//This function is responsible for applying the median filter. This uses the available function for this provided by OCV. Will edit to function made from scratch further down.
cv::Mat ImageManager::applyMedianFilter()
{
    // Apply a median filter to the image:
    cv::medianBlur(modifiedImage, modifiedImage, 5); // using a 5x5 kernel

    // Return the modified image
    return modifiedImage;
}

// Function that allows us to save the edited image as a new file with user-input given name:
// NOTE: The new, modified image is saved into the solution folder and can be found there with the given name. Adding the .png or .jpg is very important or else it wont work!!
void ImageManager::saveImage(const std::string& filename)
{
    cv::imwrite(filename, modifiedImage);
}
