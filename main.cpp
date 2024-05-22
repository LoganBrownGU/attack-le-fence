#include <vector>
#include <iostream>
#include "CardFactory.h"
#include "player/LocalCLIPlayer.h"
#include "Game.h"
#include "gui/GUI_2D.h"
#include <random>
#include <thread>


int main() {
	GUI_2D::set_window("Attack le Fence", 1000, 500);
	GUI_2D::set_background_colour(1, 1, 1, 1);
	std::thread gui_thread([] {
		GUI_2D::start();
	});

	auto players = new std::vector<PlayerType>();
	for (int i = 0; i < 3; ++i)
		players->push_back(LOCAL_CLI);

	Game game = Game(players);
	game.play();
}
