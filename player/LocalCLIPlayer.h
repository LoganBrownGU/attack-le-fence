//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_LOCALCLIPLAYER_H
#define ATTACK_LE_FENCE_LOCALCLIPLAYER_H

#include "Player.h"

class LocalCLIPlayer : public Player {
public:
	Action play() override;

	Player *actionOnPlayer(std::vector<Player *> *players) override;

	void decideCards(Deck *cards) override;

	bool useStashed() override;

private:
	/// @brief Prints a string representation of the player's cards to stdout
	void printCards();
};


#endif //ATTACK_LE_FENCE_LOCALCLIPLAYER_H
