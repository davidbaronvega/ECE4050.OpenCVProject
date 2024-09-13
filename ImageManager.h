//declaration of our ImageManager class and all of the member functions necessary for performing the required image processing.
#ifndef IMAGE_MANAGER_H // These guards prevent the header file from being read/overwritten more than once.
#define IMAGE_MANAGER_H

#include <opencv2/core/core.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

class ImageManager 
{
public:
    ImageManager(); //const.
    ~ImageManager(); //deconst.
    
    //Below are all the key member functions (methods) that will handle the image processing and movement from image to image:

    void loadImages(const std::vector<std::string>& filepaths);
    cv::Mat displayCurrentImage();
    cv::Mat nextImage();
    cv::Mat prevImage();
    cv::Mat increaseBrightness();
    cv::Mat decreaseBrightness();
    cv::Mat increaseContrast();
    cv::Mat decreaseContrast();
    cv::Mat applyMedianFilter();
    void saveImage(const std::string& filename);


    //objects of our class that will help us with storing images in the 'images' vector, referencing them via the index, 
    //and objects that will allow us to save edited images without overwriting original images.
    std::vector<cv::Mat> images;
    int current_image_index;
    cv::Mat currentImage;
    cv::Mat modifiedImage;

private:
    
};

#endif  // IMAGE_MANAGER_H