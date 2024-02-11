//
// Created by logan on 09/02/24.
//

#include "CardFactory.h"

#include <memory>
#include <random>
#include <iostream>

std::vector<std::unique_ptr<Card>> *CardFactory::generateNormalDeck() {
    auto *cards = new std::vector<std::unique_ptr<Card>>;

    for (const auto e: Suit::All) {
        for (int i = 1; i <= 13; i++)
            cards->push_back(std::make_unique<Card>(i, e));
    }

    return cards;
}

void CardFactory::shuffleDeck(std::vector<Card *> *deck) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution(0, (int) deck->size());

    for (int i = 0; i < deck->size(); i++) {
        int idx = distribution(generator);
        auto card = deck->at(idx);
        deck->erase(deck->begin() + idx);
        deck->push_back(card);
    }
}

void CardFactory::printDeck(std::vector<Card *> *deck) {
    for (const auto &card: *deck)
        std::cout << card->toString() << std::endl;
}
