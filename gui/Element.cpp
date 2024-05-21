//
// Created by logan on 21/05/24.
//

#include "Element.h"

Element::Element(int x, int y, int width, int height, float r, float g, float b, float a) {
	this->isImage = false;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->colour[0] = r;
	this->colour[1] = g;
	this->colour[2] = b;
	this->colour[3] = a;
}

Element::Element(int x, int y, int width, int height, const std::string &img_path) {
	this->isImage = false;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->image = S2D_CreateImage(img_path.c_str());
}
