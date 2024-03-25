//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_GAME_H
#define ATTACK_LE_FENCE_GAME_H


#include <vector>
#include "Card.h"
#include "player/Player.h"
#include "Deck.h"

class Game {

public:
	/// @brief Runs the game's main logic loop
	void play();

	explicit Game(std::vector<PlayerType> *players);

	~Game();

private:
	/// @brief Unused cards (i.e. The stack of cards that would be face-down on the table)
	Deck *const unusedPile;
	/// @brief Used cards (i.e. The pile of discarded cards that would be face-up on the table)
	Deck *const usedPile;
	/// @brief vector of players (alive and dead) that are involved in the game
	std::vector<Player *> *const players;


	/// @brief Handle the attack action
	/// @param player The player that is attacking
	void handleAttack(Player *player);

	/// @brief Handle the attack swap action
	/// @param player The player that is swapping another's shield
	void handleSwap(Player *player);

	/// @brief Handle the stash action
	/// @param player The player that is wanting to stash a card
	void handleStash(Player *player);

	/// @brief Finds the cards that should no longer be in play after a new health deck has been constructed, and adds them to the \p usedPile.
	/// @brief Adds all cards from \p newHealth to player's health.
	/// @param playerHealth The player's current health before \p newHealth is added
	/// @param newHealth The deck of cards that will make up the player's new health
	/// @param oldCards The cards that will need returned to \p usedPile (not including those that will need discarded from \p playerHealth)
	void cleanUp(Deck *playerHealth, Deck *newHealth, Deck *oldCards);
};


#endif //ATTACK_LE_FENCE_GAME_H
