#include "colorization.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>

/** Global Variables */
const int lshift_max = 100;
int lshift;
bool useOpenCL;

/** Matrices to store images */
Mat img;

/**
* @function on_trackbar
* @brief Called whenever lshift is changed
*
* This function re-executes the colorization process with the new value of `lshift`, which represents the displacement
* of the brightness (L channel) in the Lab color space. This adjustment influences the overall perception of brightness
* of the colorized image. The new value is passed as a parameter to the `Colorization` class, which redoes the inference
* of the neural network based on this value. The resulting image is then displayed in the "color" window.
*
* @param - The first parameter (int) is required by the callback signature but is not used directly.
* @param - The second parameter (void*) is a generic pointer that is also not used here.
*/
static void on_trackbar( int, void* )
{
    Colorization colorization(img, useOpenCL, static_cast<float>(lshift));
    Mat color = colorization.getColorized();
    imshow("color", color);
}

int main(int argc, char **argv)
{
    const string keys =
        "{ image  |                                    | path to image file }"
        "{ opencl |                                    | enable OpenCL }";
    CommandLineParser parser(argc, argv, keys);

    useOpenCL = parser.has("opencl");
    if (!parser.check())
    {
        parser.printErrors();
        return 1;
    }

    string imageFile = samples::findFile(parser.get<string>("image"));
    img = imread(imageFile);
    if (img.empty())
    {
        cout << "Can't read image from file: " << imageFile << endl;
        return 2;
    }

    /// Initialize value
    lshift = 50;

    /// Create Windows
    namedWindow("color", WINDOW_NORMAL);
    namedWindow("original", WINDOW_NORMAL);

    /// Create Trackbar
    createTrackbar("Focus Color", "color", &lshift, lshift_max, on_trackbar );
    on_trackbar(0, nullptr);

    /// Show me something
    imshow("original", img);

    /// Wait until user press some key
    waitKey();
    return 0;
}
