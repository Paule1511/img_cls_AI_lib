#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class Image {
	char channels;
	int width;
	int heigth;
public:
	uchar* pixels;
	Image(std::string filePath);

	int getWidth();
	int getHeigth();
	int getChannels();
	void extractChannel(int channel, uchar** outArray);
	void RGB2Gray();
	void BGR2Gray();
};