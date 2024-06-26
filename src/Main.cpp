#include <opencv2/opencv.hpp>
#include <argparse.hpp>
#include <iostream>

int main() {
    cv::Mat image;
    image = cv::imread("../src/test.jpg", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);

    cv::waitKey(0);
    return 0;
}