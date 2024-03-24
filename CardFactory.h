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
	static Deck *generateNormalDeck();

	static std::pair<int, int> containsSubset(Deck *set, std::pair<int, int> *subset);
};


#endif //ATTACK_LE_FENCE_CARDFACTORY_H
