#pragma once
#include "Image.h"
#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Debug.h"

Image::Image(std::string filePath) {
	cv::Mat cvImg = cv::imread(filePath);
	channels = cvImg.channels();
	width = cvImg.rows;
	heigth = cvImg.cols;
	pixels = (uchar*)malloc(3 * width * heigth);
	pixels = cvImg.data;
	Debug::test("Image Loaded");
}

void Image::RGB2Gray() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigth; j++) {
			uchar* pixel = &(&pixels[i])[j];
			uchar newPixel =
				static_cast<uchar>(pixel[0] * 0.299) +
				static_cast<uchar>(pixel[1] * 0.587) +
				static_cast<uchar>(pixel[2] * 0.114);
			(&pixels[i])[j] = newPixel;
		}
	}
}

void Image::BGR2Gray() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigth; j++) {
			uchar* pixel = &(&pixels[i])[j];
			uchar newPixel =
				static_cast<uchar>(pixel[2] * 0.299) +
				static_cast<uchar>(pixel[1] * 0.587) +
				static_cast<uchar>(pixel[0] * 0.114);
			uchar* pixelN = (newPixel, 0, 0);
			pixel = pixelN;
		}
	}

}

void Image::print() {
	std::cout << "[\n";
	for (int i = 0; i < width; i++) {
		std::cout << "[";
		for (int j = 0; j < heigth; j++) {
			uchar* pixel = &(&pixels[i])[j];
			std::cout << (int)pixel[0] << ",";
		}
		std::cout << "]\n";
	}
	std::cout << "]" << std::endl;
}