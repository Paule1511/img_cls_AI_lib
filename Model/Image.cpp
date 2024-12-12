#pragma once
#include "Image.h"
#include <string>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include "../Utils/Debug.h"

Image::Image(std::string filePath) {
	cv::Mat cvImg = cv::imread(filePath);
	channels = cvImg.channels();
	width = cvImg.cols;
	heigth = cvImg.rows;
	int size = channels * width * heigth;
	pixels = (uchar*)malloc(size);
	std::copy(cvImg.ptr(), cvImg.ptr() + (size), pixels);
}

void Image::RGB2Gray() {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int i = 0; i < width * heigth; i++) {
		uchar* pixel = &pixels[i * 3];
		uchar newPixel =
			static_cast<uchar>(pixel[0] * 0.299) +
			static_cast<uchar>(pixel[1] * 0.587) +
			static_cast<uchar>(pixel[2] * 0.114);

		newArray[i] = newPixel;
	}
	pixels = newArray;
	channels = 1;
}

void Image::extractChannel(int channel, uchar** outArray) {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int i = 0; i < width * heigth; i++) {
		uchar* pixel = &pixels[i * 3];
		newArray[i] = pixel[channel];
	}
	*outArray = newArray;
}

void Image::BGR2Gray() {
	uchar* newArray = (uchar*)malloc(width * heigth);
	for (int i = 0; i < width*heigth; i++) {
		uchar* pixel = &pixels[i*3];
		uchar newPixel =
			static_cast<uchar>(pixel[2] * 0.299) +
			static_cast<uchar>(pixel[1] * 0.587) +
			static_cast<uchar>(pixel[0]* 0.114);

		newArray[i] = newPixel;
	}
	pixels = newArray;
	channels = 1;
}

void copyPixel(uchar* pixelIn, uchar* pixelOut, int channels) {
	for (int i = 0; i < channels; i++) {
		pixelOut[i] = pixelIn[i];
	}
}


void Image::rescale(int new_width, int new_heigth) {
	uchar* pixelRescaled = (uchar*)malloc(new_width * new_heigth * channels);
	new_width = new_width > 0 ? new_width : 1;
	new_heigth = new_heigth > 0 ? new_heigth : 1;

	float widthFactor = (float)width / new_width;
	float heigthFactor = (float)heigth / new_heigth;


	for (int i = 0; i < new_heigth; i++) {
		uchar* row = &pixels[(int)(i*heigthFactor)*width*channels];
		for (int j = 0; j < new_width; j++) {
			uchar* originalPixel = &row[(int)(j * widthFactor)*channels];
			uchar* newPixel = &pixelRescaled[((i * new_width) + j)*channels];
			copyPixel(originalPixel, newPixel, channels);
		}
	}
	width = new_width;
	heigth = new_heigth;
	pixels = pixelRescaled;
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