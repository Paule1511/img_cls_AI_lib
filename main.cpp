#pragma once
#include "Model/Model.h"
#include "Utils/Debug.h"
#include "Model/Image.h"
#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

namespace fs = std::filesystem;
using namespace std;

int main() {
	Model model{100,100,1};
	Debug::test("Start");

	Image img("images/original.jpg");
	
	img.rescale(500, 500);

	cv::Mat mat2(cv::Point(img.width, img.heigth), CV_8UC3, img.pixels);
	cv::imwrite("rescale.jpg", mat2);

	img = Image("images/original.jpg");

	img.BGR2Gray();
	cv::Mat mat(cv::Point(img.width, img.heigth), CV_8UC1, img.pixels);
	cv::imwrite("gray.jpg", mat);

	
	Debug::success("End of Program ");
}