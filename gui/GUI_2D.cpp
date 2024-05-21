//
// Created by logan on 21/05/24.
//

#include <iostream>
#include "GUI_2D.h"

S2D_Window *GUI_2D::window = nullptr;

void GUI_2D::render() {

}

void GUI_2D::start() {
	S2D_Show(GUI_2D::window);
}

void GUI_2D::set_window(const std::string& title, int width, int height) {
	if (GUI_2D::window) S2D_FreeWindow(GUI_2D::window);
	GUI_2D::window = S2D_CreateWindow(title.c_str(), width, height, nullptr, GUI_2D::render, 0);
}