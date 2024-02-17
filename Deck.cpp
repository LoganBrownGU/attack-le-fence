//
// Created by logan on 17/02/24.
//

#include <random>
#include "Deck.h"

std::unique_ptr<std::vector<Card *>> Deck::deal(int n) {
    auto dealtCards = std::vector<Card *>();
    for (int i = 0; i < n; i++)
        dealtCards.push_back(this->bottom());

    return std::make_unique<std::vector<Card *>>(dealtCards);
}

void Deck::shuffle() {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution(0, (int) this->cards->size() - 1);

    for (int i = 0; i < this->cards->size(); i++) {
        int idx = distribution(generator);
        this->cards->push_back(this->pop(idx));
    }
}

std::string Deck::toString() {
    if (this->isEmpty()) return "-";

    std::string str;
    int c = 0;
    for (const auto &card: *this->cards) {
        str += card->toString();
        if (++c % 4 == 0) str += "\n";
    }

    if (c % 4 != 0) str += "\n";
    return str;
}

bool Deck::isEmpty() {
    return this->cards->empty();
}
