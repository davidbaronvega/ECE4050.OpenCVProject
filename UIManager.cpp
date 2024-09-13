//Definitions of all the functions declared within UIManager.h are found here.
#include "UIManager.h"
#include <iostream>
#include <filesystem>
#include <opencv2/core/core.hpp> //accessing core functionalities of OpenCV necessary for all OpenCV applications.
#include <opencv2/highgui/highgui.hpp> //access to a GUI created by OpenCV.
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


UIManager::UIManager()  //class constructor
{ 

}

UIManager::~UIManager() //class deconstructor
{
    
}


//Function used to display the very first image in the file directory, 
//and sequentially, any other image accessed by the user, using the index of the images vector:
void UIManager::displayImage(const cv::Mat& image) 
{
    // Checking for failure/error to locate image
    if (image.empty())
    {
        std::cout << "Could not open or find the image!" << std::endl;
        return;  
    }

    // Showing our image inside the created window with OCV functionalities:
    cv::imshow("Window", image);

    // Waiting an indefinite ammount of time for any keystroke in the window.
    cv::waitKey(0);
}

//Our 'root' function, that uses the displayMenu() function to call all other functions based on user input at the terminal:

void UIManager::start()
{
    // Defining the path to our images directory:
    std::string imagesDirectory = "C:\\Users\\12486\\Desktop\\ECE4050.Project2.OpenCV\\mridata";

    // Iterating over the files in the directory and storing each of their paths into our 'images' vector:
    std::vector<std::string> filepaths;
    for (const auto& entry : std::filesystem::directory_iterator(imagesDirectory)) 
    {
        filepaths.push_back(entry.path().string()); 
    }

    // Passing the filepaths to the loadImages function
    image_manager.loadImages(filepaths);

    // Continue with the display menu, where all of our imagemanager functions can be accessed:
    displayMenu();
}

void UIManager::displayMenu()
{
    // Initial display of the first image
    displayImage(image_manager.displayCurrentImage());

    // Menu loop
    while (true)
    {
        std::cout << "\n\n=== Menu ===\n\n";
        std::cout << "1. Next Image\n";
        std::cout << "2. Previous Image\n";
        std::cout << "3. Increase Brightness\n";
        std::cout << "4. Decrease Brightness\n";
        std::cout << "5. Increase Contrast\n";
        std::cout << "6. Decrease Contrast\n";
        std::cout << "7. Apply Median Noise Filter\n";
        std::cout << "8. Save Current Image\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:  // Next Image
        {
            displayImage(image_manager.nextImage());
            break;
        }
        case 2:  // Previous Image
        {
            displayImage(image_manager.prevImage());
            break;
        }
        case 3:  // Increase Brightness
        {
            displayImage(image_manager.increaseBrightness());
            break;
        }
        case 4:  // Decrease Brightness
        {
            displayImage(image_manager.decreaseBrightness());
            break;
        }
        case 5:  // Increase Contrast
        {
            displayImage(image_manager.increaseContrast());
            break;
        }
        case 6:  // Decrease Contrast
        {
            displayImage(image_manager.decreaseContrast());
            break;
        }
        case 7:  // Apply Median Noise Filter
        {
            displayImage(image_manager.applyMedianFilter());
            break;
        }
        case 8:  // Save Current Image
        {
            std::string filename;
            std::cout << "Enter the filename to save the image (include the extension, e.g., '.jpg'): ";
            std::cin >> filename;
            image_manager.saveImage(filename);
            std::cout << "Image saved as " << filename << ".\n";
            break;
        }
        case 9:  // Exit
            return;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
    }
}
