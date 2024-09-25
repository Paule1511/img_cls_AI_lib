#pragma once
#include "Model/Model.h"
#include "Utils/Debug.h"
#include "Utils/Image.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace std;

int main() {
	Model model{ 10,10,10 };
	vector<cv::Mat> imgs = vector<cv::Mat>();
	vector<cv::Vec3b*> imgsV = vector<cv::Vec3b*>();
	for (auto& entry : fs::recursive_directory_iterator("images/")) {
		if (entry.path().extension() == ".jpg") {
			cv::Mat img = cv::imread(entry.path().string());
			imgs.push_back(img);
			cv::Vec3b* imgArr = &img.at<cv::Vec3b>(1, 1);
			imgsV.push_back(imgArr);
		}
	}
	cout << imgs.size() << endl;
	cout << imgsV.size() << endl;
	Debug::success("End of Program ");
}