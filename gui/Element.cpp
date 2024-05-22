//
// Created by logan on 21/05/24.
//

#include <simple2d.h>
#include "Element.h"

Element::Element(float x, float y, float width, float height, float r, float g, float b, float a) {
	this->_isImage = false;
	this->x[0] = x; 		this->y[0] = y;
	this->x[1] = x + width; this->y[1] = y;
	this->x[2] = x + width; this->y[2] = y + height;
	this->x[3] = x; 		this->y[3] = y + height;

	this->width = width;
	this->height = height;

	this->colour = new S2D_Color();
	this->colour->r = r;
	this->colour->g = g;
	this->colour->b = b;
	this->colour->a = a;
	this->image = nullptr;
}

Element::Element(float x, float y, float width, float height, const std::string &img_path) {
	this->_isImage = true;
	this->x[0] = x; 		this->y[0] = y;
	this->x[1] = x + width; this->y[1] = y;
	this->x[2] = x + width; this->y[2] = y + height;
	this->x[3] = x; 		this->y[3] = y + height;

	this->width = width;
	this->height = height;

	this->image = S2D_CreateImage(img_path.c_str());
	this->colour = nullptr;
}

const float *Element::getX() const {
	return x;
}

const float *Element::getY() const {
	return y;
}

float Element::getWidth() const {
	return width;
}

float Element::getHeight() const {
	return height;
}

bool Element::isImage() const {
	return _isImage;
}

S2D_Color *Element::getColour() const {
	return colour;
}

S2D_Image *Element::getImage() const {
	return image;
}
