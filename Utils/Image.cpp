#pragma once
#include "Image.h"
#include <string>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include "Debug.h"

Image::Image(std::string filePath) {
	cv::Mat cvImg = cv::imread(filePath);
	channels = cvImg.channels();
	width = cvImg.rows;
	heigth = cvImg.cols;
	int size = channels * width * heigth;
	pixels = (uchar*)malloc(size);
	std::copy(cvImg.ptr(), cvImg.ptr() + (size), pixels);
}

void Image::RGB2Gray() {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int j = 0; j < width * heigth; j++) {
		uchar* pixel = &pixels[j * 3];
		uchar newPixel =
			static_cast<uchar>(pixel[0] * 0.299) +
			static_cast<uchar>(pixel[1] * 0.587) +
			static_cast<uchar>(pixel[2] * 0.114);

		newArray[j] = newPixel;
	}
	pixels = newArray;
	channels = 1;
}

void Image::extractChannel(int channel, uchar** outArray) {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int j = 0; j < width * heigth; j++) {
		uchar* pixel = &pixels[j * 3];
		newArray[j] = pixel[channel];
	}
	*outArray = newArray;
}

void Image::BGR2Gray() {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int j = 0; j < width*heigth; j++) {
		uchar* pixel = &pixels[j*3];
		uchar newPixel =
			static_cast<uchar>(pixel[2] * 0.299) +
			static_cast<uchar>(pixel[1] * 0.587) +
			static_cast<uchar>(pixel[0]* 0.114);

		newArray[j] = newPixel;
	}
	pixels = newArray;
	channels = 1;
}


int Image::getWidth() {
	return width;
}

int Image::getHeigth() {
	return heigth;
}

int Image::getChannels(){
	return channels;
}