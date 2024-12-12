#pragma once
#include "Image.h"
class Model {
private:
	int opt_width;
	int opt_height;
	int color_depth;
public:
	Model(int opt_width, int opt_height, int color_depth);
	void printModel();
	float* evaluate();
	int predict();
	void preprocess(Image* img);
	void preprocess(uchar** pixelData);
};