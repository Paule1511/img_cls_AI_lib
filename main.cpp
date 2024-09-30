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

	Image img("images/test/test/0005.jpg");
	
	img.rescale(0, 0);

	cv::Mat mat(cv::Point(img.width, img.heigth), CV_8UC3, img.pixels);
	cv::imwrite("upscaled.jpg", mat);
	
	Debug::success("End of Program ");
}