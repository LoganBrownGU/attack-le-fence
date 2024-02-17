//
// Created by logan on 17/02/24.
//

#include "Deck.h"

std::unique_ptr<std::vector<Card *>> Deck::deal(int n) {
    auto dealtCards = std::vector<Card *>();
    for (int i = 0; i < n; i++)
        dealtCards.push_back(this->bottom());

    return std::make_unique<std::vector<Card *>>(dealtCards);
}
