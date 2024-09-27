#pragma once
#include "Model/Model.h"
#include "Utils/Debug.h"
#include "Utils/Image.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace std;

void BGR2RGB(uchar* bytes, int width, int heigth) {
	uchar temp;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigth; j++) {
			uchar* pixel = &(&(bytes)[i])[j];
			temp = pixel[0];
			pixel[0] = pixel[2];
			pixel[2] = temp;
		}
	}
}

void BGR2Gray(uchar* bytes, int width, int heigth) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigth; j++) {
			uchar* pixel = &(&bytes[i])[j];
			uchar newPixel = 
				static_cast<uchar>(pixel[2] * 0.299) +
				static_cast<uchar>(pixel[1] * 0.587) +
				static_cast<uchar>(pixel[0] * 0.114);
			(&bytes[i])[j] = newPixel;
		}
	}
}

int main() {
	Model model{ 10,10,10 };
	Debug::test("Start");
	
	cv::Mat cvimg = cv::imread("images/test/test/0005.jpg");

	Image img("images/test/test/0005.jpg");
	cv::Mat cvImg(cv::Point(img.width, img.heigth), CV_8UC3, img.pixels);
	cv::imwrite("newfile.jpg", cvImg);

	cout << "\n\n\n\n\n" << endl;
	img.BGR2Gray();

	cv::Mat cvImg2(cv::Point(img.width, img.heigth), CV_8UC1, img.pixels);

	cv::imwrite("grey.jpg", cvImg2);
	
	Debug::success("End of Program ");
}