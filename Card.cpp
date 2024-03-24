//
// Created by logan on 08/02/24.
//

#include "Card.h"

int Card::getValue() const {
	return value;
}

Suit::Type Card::getSuit() {
	return this->suit;
}

Card::Card(int value, Suit::Type suit) : value(value), suit(suit) {}

std::string Card::toString() {
	return "|  " + std::to_string(this->value) + " of " + (this->value < 10 ? " " : "") + Suit::values[this->suit] +
		   "  |";
}
