#include <opencv2/opencv.hpp>
#include <argparse.hpp>
#include <iostream>
#include <filesystem>
#include <vector>

int main(int argc, char *argv[]) 
{   
    // using the argparser reading dataset name
    argparse::ArgumentParser parser("Reading the location of the dataset");

    parser.add_argument("Dataset")
            .help("Input Dataset Folder Name")
            .required();

    try 
    {
        parser.parse_args(argc, argv);
    }

    catch (const std::runtime_error & err) 
    {
        std::cerr << err.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    auto dataset = parser.get<std::string>("Dataset");

    std::cout << "Reading Imgs of Dataset : " << dataset << std::endl;

    // reading the multiple images of the folder
    std::vector<cv::Mat> StackedImgs;

    for(const auto&file : std::filesystem::directory_iterator("../src/" + dataset))
    {
        cv::Mat img = cv::imread(file.path().string());
        StackedImgs.push_back(img);
    }

    // showing each images separately
    for (int i = 0; i < StackedImgs.size(); ++i) {
        cv::imshow("Image " + std::to_string(i+1), StackedImgs[i]);
        cv::waitKey(0);
    }

    cv::waitKey(0);
    return 0;
}