//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_CARDFACTORY_H
#define ATTACK_LE_FENCE_CARDFACTORY_H

#include <vector>
#include <memory>

#include "Card.h"
#include "Deck.h"

class CardFactory {
public:
	/// @brief Creates a new standard 52-card deck
	/// @returns A pointer to the deck
	static Deck *generateNormalDeck();

	/// @brief Checks if a deck contains a pair of numeric values
	/// @returns The indices of the cards that match the criteria.
	/// @returns {-1, -1} if values are not found.
	static std::pair<int, int> containsSubset(Deck *set, std::pair<int, int> *subset);
};


#endif //ATTACK_LE_FENCE_CARDFACTORY_H
