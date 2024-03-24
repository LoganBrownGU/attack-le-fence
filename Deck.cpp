//
// Created by logan on 17/02/24.
//

#include <random>
#include <iostream>
#include "Deck.h"

Deck *Deck::deal(int n) {
	auto dealtCards = new Deck();
	for (int i = 0; i < n; i++)
		dealtCards->place_top(this->pop_bottom());

	return dealtCards;
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
	this->cards->erase(this->cards->end() - 1);
	return card;
}

Card *Deck::pop(int i) {
	Card *card = this->cards->at(i);
	this->cards->erase(this->cards->begin() + i);
	return card;
}

Deck::Deck() : cards(new std::vector<Card *>()) {}

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

void Deck::clear() {
	this->cards->clear();
}

void Deck::copy_from(Deck *other) {
	for (const auto &card: *other)
		this->place_top(card);
}

Card *Deck::pop(Card *c) {
	int i = 0;
	for (const auto &card: *this->cards) {
		if (card == c) {
			auto &rcard = card;
			this->cards->erase(this->cards->begin() + i);
			return rcard;
		}
		i++;
	}

	return nullptr;
}
