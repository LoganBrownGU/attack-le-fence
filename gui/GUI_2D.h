//
// Created by logan on 21/05/24.
//

#ifndef ATTACK_LE_FENCE_GUI_2D_H
#define ATTACK_LE_FENCE_GUI_2D_H


#include <string>
#include <simple2d.h>
#include <vector>
#include "Element.h"

class GUI_2D {
private:
	static S2D_Window *window;

	/// @brief vector of all elements in GUI
	static std::vector<Element *> elements;

	static void render();
	static void handle_click(S2D_Event e);
	static void handle_left_click(S2D_Event *e);

public:
	static void set_window(const std::string& title, int width, int height);
	static void start();
	static void set_background_colour(float r, float g, float b, float a);

	/// @brief adds new element to the GUI
	/// @param element element to be added
	static void add_element(Element *element);

	/// @brief removes all elements that match the given pointer from the array
	/// @param element element to be removed
	/// @returns true if element found
	static bool remove_element(Element *element);
};


#endif //ATTACK_LE_FENCE_GUI_2D_H
