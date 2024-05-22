//
// Created by logan on 21/05/24.
//

#ifndef ATTACK_LE_FENCE_ELEMENT_H
#define ATTACK_LE_FENCE_ELEMENT_H


#include <string>

class Element {
private:
	/// @brief coordinates of four corners of element clockwise from top left
	float x[4], y[4];
	float width, height;
	bool _isImage;
	S2D_Color *colour;
	S2D_Image *image;

public:
	Element(float x, float y, float width, float height, float r, float g, float b, float a);
	Element(float x, float y, float width, float height, const std::string& img_path);

	const float *getX() const;

	const float *getY() const;

	float getWidth() const;

	float getHeight() const;

	bool isImage() const;

	S2D_Color *getColour() const;

	S2D_Image *getImage() const;
};


#endif //ATTACK_LE_FENCE_ELEMENT_H
