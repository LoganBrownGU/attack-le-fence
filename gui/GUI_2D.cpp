//
// Created by logan on 21/05/24.
//

#include <iostream>
#include "GUI_2D.h"

S2D_Window *GUI_2D::window = nullptr;
std::vector<Element *> GUI_2D::elements;

void GUI_2D::render() {
	for (const auto &element: GUI_2D::elements)
	{
		if (element->isImage())
		{
			// todo render image
		} else
		{

		}
	}
}

void GUI_2D::start() {
	S2D_Show(GUI_2D::window);
}

void GUI_2D::set_window(const std::string& title, int width, int height) {
	if (GUI_2D::window) S2D_FreeWindow(GUI_2D::window);
	char *c_title = (char *) malloc(title.length() + 1);
	strncpy(c_title, title.c_str(), title.length());
	GUI_2D::window = S2D_CreateWindow(c_title, width, height, nullptr, GUI_2D::render, 0);
}

void GUI_2D::set_background_colour(float r, float g, float b, float a) {
	GUI_2D::window->background.r = r;
	GUI_2D::window->background.g = g;
	GUI_2D::window->background.b = b;
	GUI_2D::window->background.a = a;
}

void GUI_2D::add_element(Element *element) {
	GUI_2D::elements.push_back(element);
}

bool GUI_2D::remove_element(Element *element) {
	bool found_element = false;
	for (int i = 0; i < GUI_2D::elements.size(); i++)
	{
		if (element == GUI_2D::elements.at(i)) {
			elements.erase(GUI_2D::elements.begin() + i);
			found_element = true;
		}
	}
	return found_element;
}
