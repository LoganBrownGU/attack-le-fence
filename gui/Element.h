//
// Created by logan on 21/05/24.
//

#ifndef ATTACK_LE_FENCE_ELEMENT_H
#define ATTACK_LE_FENCE_ELEMENT_H


#include <simple2d.h>
#include <string>

class Element {
private:
	int x, y, width, height;
	bool isImage;
	float colour[4];
	S2D_Image *image;

public:
	Element(int x, int y, int width, int height, float r, float g, float b, float a);
	Element(int x, int y, int width, int height, const std::string& img_path);
};


#endif //ATTACK_LE_FENCE_ELEMENT_H
