#include <vector>
#include <iostream>
#include "CardFactory.h"
#include "player/LocalCLIPlayer.h"
#include "Game.h"
#include <simple2d.h>
#include <random>


int main() {

	auto players = new std::vector<PlayerType>();
	for (int i = 0; i < 3; ++i)
		players->push_back(LOCAL_CLI);

	Game game = Game(players);
	game.play();
}
