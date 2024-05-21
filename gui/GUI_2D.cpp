//
// Created by logan on 21/05/24.
//

#include <iostream>
#include "GUI_2D.h"

S2D_Window *GUI_2D::window = nullptr;
S2D_Color *GUI_2D::background_colour = nullptr;

void GUI_2D::render() {
	S2D_GL_Clear(*GUI_2D::background_colour);
}

void GUI_2D::start() {
	S2D_Show(GUI_2D::window);
}

void GUI_2D::set_window(const std::string& title, int width, int height) {
	if (GUI_2D::window) S2D_FreeWindow(GUI_2D::window);
	GUI_2D::window = S2D_CreateWindow(title.c_str(), width, height, nullptr, GUI_2D::render, 0);
}

void GUI_2D::set_background_colour(float r, float g, float b, float a) {
	delete GUI_2D::background_colour;

	GUI_2D::background_colour = new S2D_Color();
	GUI_2D::background_colour->r = r;
	GUI_2D::background_colour->g = g;
	GUI_2D::background_colour->b = b;
	GUI_2D::background_colour->a = a;
}

void GUI_2D::add_element(Element *element) {
	GUI_2D::elements.push_back(element);
}

bool GUI_2D::remove_element(Element *element) {
	bool found_element = false;
	for (int i = 0; i < GUI_2D::elements.size(); i++)
	{
		if (element == GUI_2D::elements.at(i)) {
			GUI_2D::elements.erase(GUI_2D::elements.begin() + i);
			found_element = true;
		}
	}
	return found_element;
}
