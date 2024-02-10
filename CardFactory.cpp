//
// Created by logan on 09/02/24.
//

#include "CardFactory.h"

std::unique_ptr<std::vector<Card *>> CardFactory::generateNormalDeck() {
    std::unique_ptr<std::vector<Card *>> cards(new std::vector<Card *>);

    for (const auto e: Suit::All) {
        for (int i = 1; i <= 13; i++)
            cards->push_back(new Card(i, e));
    }

    return cards;
}
