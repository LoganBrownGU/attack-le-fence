//
// Created by logan on 17/02/24.
//

#include <random>
#include "Deck.h"

std::unique_ptr<std::vector<Card *>> Deck::deal(int n) {
    auto dealtCards = std::vector<Card *>();
    for (int i = 0; i < n; i++)
        dealtCards.push_back(this->pop_bottom());

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

int Deck::totalValue() {
    int total = 0;
    for (const auto &card: *this->cards)
        total += card->getValue();

    return total;
}

Card *Deck::at(int i) {
    return this->cards->at(i);
}

Card *Deck::pop_top() {
    Card *card = this->cards->at(0);
    this->cards->erase(this->cards->begin());
    return card;
}

Card *Deck::pop_bottom() {
    Card *card = this->cards->at(this->cards->size() - 1);
    this->cards->erase(this->cards->end());
    return card;
}

Card *Deck::pop(int i) {
    Card *card = this->cards->at(i);
    this->cards->erase(this->cards->begin() + i);
    return card;
}

Deck::Deck() : cards (new std::vector<Card *>()) {}

Deck::~Deck() {
    delete this->cards;
}

void Deck::place_top(Card *card) {
    this->cards->insert(this->cards->begin(), card);
}

void Deck::place_bottom(Card *card) {
    this->cards->push_back(card);
}

size_t Deck::size() {
    return this->cards->size();
}
