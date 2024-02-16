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
    if (deck->empty()) return;
    int c = 0;
    for (const auto &card: *deck) {
        std::cout << card->toString();
        if (++c % 4 == 0) std::cout << std::endl;
    }

    if (c % 4 != 0) std::cout << std::endl;
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

int CardFactory::totalValue(std::vector<Card *> *deck) {
    int total = 0;
    for (const auto &card: *deck)
        total += card->getValue();

    return total;
}

std::pair<int, int> CardFactory::containsSubset(std::vector<Card *> *set, std::pair<int, int> *subset) {
    int idxFirst = -1, idxSecond = -1;

    for (int i = 0; i < set->size(); i++) {
        if (subset->first == set->at(i)->getValue())            idxFirst = i;
        else if (subset->second == set->at(i)->getValue())      idxSecond = i;

        if (idxFirst != -1 && idxSecond != -1) break;
    }

    return std::pair{idxFirst, idxSecond};
}
