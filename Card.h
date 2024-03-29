//
// Created by logan on 08/02/24.
//

#ifndef ATTACK_LE_FENCE_CARD_H
#define ATTACK_LE_FENCE_CARD_H

#include <memory>
#include <string>

namespace Suit {
	enum Type {
		HEARTS = 0,
		SPADES = 1,
		CLUBS = 2,
		DIAMONDS = 3
	};

	static const Type All[] = {HEARTS, SPADES, CLUBS, DIAMONDS};
	static const std::string values[] = {"\u2665", "\u2660", "\u2663", "\u2666"};
}

class Card {

private:
	/// @brief Numeric value of the card
	const int value;
	/// @brief The card's suit
	Suit::Type suit;

public:

	Card(int value, Suit::Type suit);

	[[nodiscard]] int getValue() const;

	[[nodiscard]] Suit::Type getSuit();

	std::string toString();
};


#endif //ATTACK_LE_FENCE_CARD_H
