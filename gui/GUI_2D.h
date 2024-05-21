//
// Created by logan on 21/05/24.
//

#ifndef ATTACK_LE_FENCE_GUI_2D_H
#define ATTACK_LE_FENCE_GUI_2D_H


#include <string>
#include <simple2d.h>

class GUI_2D {
private:
	static S2D_Window *window;

	static void render();


public:
	static void set_window(const std::string& title, int width, int height);
	static void start();
};


#endif //ATTACK_LE_FENCE_GUI_2D_H
