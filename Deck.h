//
// Created by logan on 17/02/24.
//

#ifndef ATTACK_LE_FENCE_DECK_H
#define ATTACK_LE_FENCE_DECK_H


#include <vector>
#include "Card.h"

class Deck {
private:
	/// @brief vector of all cards in the deck
	std::vector<Card *> *const cards;

public:
	Deck();

	~Deck();

	/// @brief Takes n cards from the deck
	/// @returns n cards as a vector
	Deck *deal(int n);

	/// @brief The sum of all the values of the cards in the deck
	int totalValue();

	/// @brief The card at position i
	Card *at(int i);

	/// @brief Removes card at the top of the deck (if it was facing upwards)
	/// @returns The card that was removed
	Card *pop_top();

	/// @brief Removes card at the bottom of the deck (if it was facing upwards)
	/// @returns The card that was removed
	Card *pop_bottom();

	/// @brief Removes the card at index i
	/// @returns Removed card
	Card *pop(int i);

	/// @brief Removes card c
	/// @returns Card c
	Card *pop(Card *c);

	/// @brief Checks if the deck is clear
	bool isEmpty();

	/// @brief Number of cards in deck
	size_t size();

	/// @brief A string representation of the deck
	std::string toString();

	/// @brief Places card on top of deck
	void place_top(Card *card);

	/// @brief Places card on bottom of deck
	void place_bottom(Card *card);

	/// @brief Copies cards from other into this deck
	void copy_from(Deck *other);

	/// @brief Randomises the order of the deck
	void shuffle();

	/// @brief Empties deck
	void clear();

	class Iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Card *;
		using pointer = Card **;  // or also value_type*
		using reference = Card *&;  // or also value_type&

		Iterator(int index, std::vector<Card *> *cards) : index(index), cards(cards) {}

		reference operator*() const { return cards->at(index); }

		pointer operator&() { return &cards->at(index); }

		Iterator &operator++() {
			index++;
			return *this;
		}

		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator==(const Iterator &a, const Iterator &b) { return (a.index == b.index) && (a.cards == b.cards); }

		friend bool operator!=(const Iterator &a, const Iterator &b) { return (a.index != b.index) && (a.cards == b.cards); }

	private:
		std::vector<Card *> *cards;
		int index;
	};

	Iterator begin() { return {0, cards}; }

	Iterator end() { return {static_cast<int>(cards->size()), cards}; }
};


#endif //ATTACK_LE_FENCE_DECK_H
