//This file contains all the class and member function definitions for the 
#ifndef UI_MANAGER_H // These guards prevent the header file from being read/overwritten more than once.
#define UI_MANAGER_H

#include "ImageManager.h"
#include <string>

using namespace std;
using namespace cv;




class UIManager 
{
public:
    UIManager();
    ~UIManager();

    void start();   //function called in the main, which provides routing to all other necessary functions.
    void displayMenu();
    void displayImage(const cv::Mat& image);
    ImageManager image_manager;  //**creating an object of our class here that allows us to reference the selected image and modify it temporarily and accordingly.

private:
    //I wanted to keep some of the member functions for UIManager and Image Manager private but was having some compiling issues 
    //when nesting the class functions within one another, so I left them all public to avoid any issues.
   
};

#endif  // UI_MANAGER_H

