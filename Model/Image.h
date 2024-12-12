#pragma once
#include <opencv2/opencv.hpp>
#include <string>

void copyPixel(uchar* pixelIn, uchar* pixelOut, int channels);

class Image {
public:
	char channels;
	int width;
	int heigth;
	uchar* pixels;
	Image(std::string filePath);

	int getWidth();
	int getHeigth();
	int getChannels();
	void extractChannel(int channel, uchar** outArray);
	void RGB2Gray();
	void BGR2Gray();
	void rescale(int new_width, int new_heigth);
};