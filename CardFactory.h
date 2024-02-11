//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_CARDFACTORY_H
#define ATTACK_LE_FENCE_CARDFACTORY_H

#include <vector>
#include <memory>

#include "Card.h"

class CardFactory {
public:
    static std::vector<Card *> *generateNormalDeck();
    static void shuffleDeck(std::vector<Card *> *deck);
    static void printDeck(std::vector<Card *> *deck);
    static std::unique_ptr<std::vector<Card *>> dealCards(std::vector<Card *> *deck, int n);
};


#endif //ATTACK_LE_FENCE_CARDFACTORY_H
