//
// Created by logan on 09/02/24.
//

#include "CardFactory.h"

#include <memory>
#include <random>
#include <iostream>

std::vector<Card *> *CardFactory::generateNormalDeck() {
    auto *cards = new std::vector<Card *>;

    for (const auto e: Suit::All) {
        for (int i = 1; i <= 13; i++)
            cards->push_back(new Card(i, e));
    }

    return cards;
}

void CardFactory::shuffleDeck(std::vector<Card *> *deck) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution(0, (int) deck->size() - 1);

    for (int i = 0; i < deck->size(); i++) {
        int idx = distribution(generator);
        auto card = deck->at(idx);
        deck->erase(deck->begin() + idx);
        deck->push_back(card);
    }
}

void CardFactory::printDeck(std::vector<Card *> *deck) {
    int c = 0;
    for (const auto &card: *deck) {
        std::cout << "| \t" << card->toString() << "\t";
        if (++c % 4 == 0) std::cout << " | \n";
    }

    if (c % 4 != 0) std::cout << "|\n";
    std::cout << std::endl;
}

std::unique_ptr<std::vector<Card *>> CardFactory::dealCards(std::vector<Card *> *deck, int n) {
    auto cards = std::make_unique<std::vector<Card *>>(std::vector<Card *>());

    for (int i = 0; i < n; i++) {
        cards->push_back(deck->back());
        deck->pop_back();
    }

    return cards;
}
