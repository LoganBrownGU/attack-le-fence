//
// Created by logan on 21/05/24.
//

#include "Element.h"

Element::Element(int x, int y, int width, int height, float r, float g, float b, float a) {
	this->_isImage = false;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->colour = new S2D_Color();
	this->colour->r = r;
	this->colour->g = g;
	this->colour->b = b;
	this->colour->a = a;
	this->image = nullptr;
}

Element::Element(int x, int y, int width, int height, const std::string &img_path) {
	this->_isImage = false;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->image = S2D_CreateImage(img_path.c_str());
	this->colour = nullptr;
}

int Element::getX() const {
	return x;
}

int Element::getY() const {
	return y;
}

int Element::getWidth() const {
	return width;
}

int Element::getHeight() const {
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
