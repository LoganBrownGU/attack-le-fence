//
// Created by logan on 09/02/24.
//

#include "CardFactory.h"

#include <memory>

std::vector<std::unique_ptr<Card>> *CardFactory::generateNormalDeck() {
    auto *cards = new std::vector<std::unique_ptr<Card>>;

    for (const auto e: Suit::All) {
        for (int i = 1; i <= 13; i++)
            cards->push_back(std::make_unique<Card>(i, e));
    }

    return cards;
}
