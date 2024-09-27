#pragma once
#include "Model/Model.h"
#include "Utils/Debug.h"
#include "Utils/Image.h"
#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

namespace fs = std::filesystem;
using namespace std;

int main() {
	Model model{ 10,10,10 };
	Debug::test("Start");
	
	cv::Mat cvimg = cv::imread("images/test/test/0005.jpg");

	Image img("images/test/test/0005.jpg");
	cv::Mat cvImg(cv::Point(img.getWidth(), img.getHeigth()), CV_8UC3, img.pixels);
	cv::imwrite("newfile.jpg", cvImg);
	
	Debug::success("End of Program ");
}