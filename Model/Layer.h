#pragma once

class Layer {
	float* weights;
	void (*func)(float*, int, int);
	Layer(void (*layerFunc)(float*, int, int));
};