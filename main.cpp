//
// David Baron-Vega
// Access ID: GF7068
// Created in July of 2023 for Spring/Summer ECE4050.
// ECE4050.Project2.OpenCV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <vector>
#include <string>
#include <opencv2/core/core.hpp> //accessing core functionalities of OpenCV necessary for all OpenCV applications.
#include <opencv2/highgui/highgui.hpp> //access to a GUI created by OpenCV.
#include <opencv2/imgproc.hpp>  //Access to image process functions and capabilties defined by OpenCV.
#include "ImageManager.h"       // Including all of the written header files to access functions.
#include "UIManager.h"
#include <iostream> //standard reading in/out to console for c++.
#include <filesystem> //This is a open-source library available for C++ 17 or later compatible compilers. 
					 //This library may allow us to simplify our code and navigate images more efficiently (both lines of code and compile-time wise.)

	using namespace cv;		// allows us to use classes and function defined in the CV libraries.
	using namespace std;	// basic I/O namespace. Getting in the habit of explicitly writing out namespaces for greater flexibility, though.
	namespace fs = filesystem; //creating an alias for std::filesystem to make the code look cleaner.


//The entire functionality of this program is created and described within the UIManager.cpp file and the ImageManger.cpp file
//All that is needed to initialize and access all the neccessary classes and functions can be accessed within this one simple start command!


    int main()
    {
        UIManager uimanager;
        uimanager.start();
        return 0; //return value will appear when program executes correctly.
    }















	//All of the commented code below is just previous work done while getting acquainted with OpenCV functions.
    //None of this is needed for the function but just shows some of the work done with reading and writing to image files.
	
	/*


    std::string path = "C:\\Users\\12486\\Desktop\\ECE4050.Project2.OpenCV\\mridata"; //Creating a string named 'path' that is the path to our data directory.

    for (const auto& entry : fs::directory_iterator(path)) //printing all of the file names to validate that we are able to access them all.
        std::cout << entry.path() << std::endl;
    //great, it appears we can read/write all the files in the directory. However, they are not printing in order....
    //UPDATE: I was able to fix the order in which the images were being read by 'zero-padding' all the names of the images.







    for (const auto& entry : fs::directory_iterator(path)) //Iterating over each file in the directory
    {
        string imagePath = entry.path().string(); //Converting the path to a string
        cout << "Processing: " << imagePath << endl;

        Mat image; //defining an object called image of the classtype Matrix. This class is definined in the cv namespace.

        image = imread(imagePath); //using the imread function to load the image from the path.

        if (image.empty()) //creating validation/error-checking for the loading process.
        {
            cout << "The image was not found in the provided filepath." << endl;
        }
        else
        {
            cout << "The Dimensions of this image are:" << image.rows << "x" << image.cols << endl; //printing the dimensions of the image
            imshow("Display Image", image); //using function imshow from namespace cv to load the image and some text above it.
            waitKey(0); //waitKey is a function defined in cv namespace that allows for an image to load and then closed after specified number of milliseconds.
            // when we input 0, the image is loaded indefinitely.

// Here, you can add any image processing code that you want to apply to each image.
// After processing, you can save the image using imwrite()

          //  string outputImagePath = "C:\\path\\to\\output\\directory\\" + entry.path().filename().string();
           // imwrite(outputImagePath, image); //Write the image to a file. Replace 'image' with the processed image if you have done any processing.
        }
    }



    */

	/*int main()
	{
		Mat image = Mat::zeros(300, 600, CV_8UC3);
		circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
		circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
		imshow("Display Window", image);
		waitKey(0);
		return 0;
	}*/