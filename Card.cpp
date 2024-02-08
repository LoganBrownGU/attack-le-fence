//
// Created by logan on 08/02/24.
//

#include "Card.h"

int Card::getValue() const {
    return value;
}

std::unique_ptr<Suit> *Card::getSuit() const {
    return suit;
}

Card::Card(int value, std::unique_ptr<Suit> *suit) : value(value), suit(suit) {}
