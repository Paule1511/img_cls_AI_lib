#pragma once

class Model {
private:
	int opt_width;
	int opt_height;
	int color_depth;
public:
	Model(int opt_width, int opt_height, int color_depth);
	void printModel();
};