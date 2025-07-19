#include <gtest/gtest.h>
#include <opencv2/imgcodecs.hpp>
#include "../src/colorization.hpp"

/**
* @brief Unit test to verify the behavior of the Colorization class.
*
* This test verifies that the getColorized() function returns a valid image
* with the same dimensions as the input image. The image used in the test
* must be available at the specified path.
*/
TEST(ColorizationTest, ReturnsImageOfExpectedTypeAndSize) {
    // Load a test image
    cv::Mat img = cv::imread("imgs/ansel_adams.jpg");
    ASSERT_FALSE(img.empty());

    // Performs colorization
    Colorization colorizer(img, false, 50.0f);
    cv::Mat result = colorizer.getColorized();

    // Tests if the result is not empty
    EXPECT_FALSE(result.empty());

    // Tests if the resulting image size is equal to the original
    EXPECT_EQ(result.size(), img.size());
}

/**
* @brief Main function for running tests with Google Test.
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
