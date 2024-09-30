#pragma once
#include "Model.h"
#include "Image.h"
#include <iostream>

using namespace std;

Model::Model(int opt_width, int opt_height, int color_depth) {
	//Array erstellen
	//Gewichte initializieren (Random oder nicht)
}

void Model::printModel() {
	cout << "\033[31mZU IMPLEMENTIEREN!!!\033[0m" << endl;
	//Model aufbau anzeigen (gewicht zahl, opt_width, opt_height)
}

void Model::preprocess(Image* img) {
	if (img->heigth != opt_height || img->width != opt_width) {
		img->rescale(opt_width, opt_height);
	}


}