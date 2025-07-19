#ifndef COLORIZATION_HPP
#define COLORIZATION_HPP

#include <opencv2/dnn.hpp>

using namespace cv;
using namespace std;

/**
* @brief Constructor for the Colorization class
* @param img Input image (grayscale)
* @param useOpenCL Enables the use of OpenCL to speed up inference (default: false)
* @param lShift Value to be subtracted from the L channel of the Lab image (default: 50.0f)
*/
class Colorization {
public:
    Colorization(const Mat& img, bool useOpenCL = false, float lShift = 50.0f);
    Mat getColorized();
    /**
    * @brief Returns the color image
    * @return Mat containing the image in colors (BGR)
    */
private:
    Mat color;
};

#endif // COLORIZATION_HPP
