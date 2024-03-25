//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_PLAYER_H
#define ATTACK_LE_FENCE_PLAYER_H


#include <vector>
#include "../Deck.h"

class Card;

enum Action {
	ATTACK,
	SWAP,
	STASH
};

enum PlayerType {
	BOT,
	LOCAL_CLI,
	REMOTE_CLI
};

class Player {

public:
	/// @brief Asks player for Action they want to perform
	/// @returns The Action the player wants to perform
	virtual Action play() = 0;

	/// @brief Asks the player which player they want to perform an Action on
	/// @returns Pointer to the player that they want to perform the Action on
	/// @param players vector of all players in game
	virtual Player *actionOnPlayer(std::vector<Player *> *players) = 0;

	/// @brief Ask the player to choose which card(s) to use as their shield
	/// @param cards Three cards from which to choose
	virtual void decideCards(Deck *cards) = 0;

	/// @brief Ask the player if they want to use their stashed card
	/// @returns False if the player does not want to user their stashed card, true otherwise
	virtual bool useStashed() = 0;

	/// @brief Place card in player's stash
	/// @param card The card to be stashed
	void stashCard(Card *card);

	/// @brief Removes player's stashed card
	/// @returns The player's stashed card
	Card *playStashed();

	/// @returns true if the player has a stashed card
	bool hasStashed();

	/// @brief Sets _isAlive to false
	void kill();

	[[nodiscard]] Deck *getShield() const;

	[[nodiscard]] Deck *getHealth() const;

	[[nodiscard]] bool isAlive() const;

	Player();

	~Player();

protected:
	// IMPORTANT:   Player does not have ownership over any cards.
	//              vectors should never be replaced, only contents

	/// @brief Deck of cards that makes up the player's shield
	Deck *const shield;
	/// @brief Deck of cards that makes up the player's healths
	Deck *const health;
	/// @brief Pointer to player's stashed card
	Card *stashedCard;
	/// @brief true if player is still alive
	bool _isAlive;
};


#endif //ATTACK_LE_FENCE_PLAYER_H
