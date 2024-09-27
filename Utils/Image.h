#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class Image {
public:
	uchar* pixels;
	char channels;
	int width;
	int heigth;
	Image(std::string filePath);

	void print();
	void RGB2Gray();
	void BGR2Gray();
};