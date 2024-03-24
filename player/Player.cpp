//
// Created by logan on 09/02/24.
//

#include "Player.h"

void Player::stashCard(Card *card) {
	this->stashedCard = card;
}

Card *Player::playStashed() {
	Card *card = this->stashedCard;
	this->stashedCard = nullptr;
	return card;
}

Player::~Player() {
	delete this->health;
	delete this->shield;
}

bool Player::hasStashed() {
	return this->stashedCard;
}

Player::Player() : shield(new Deck()),
				   health(new Deck()), stashedCard(nullptr) {}

Deck *Player::getShield() const {
	return shield;
}

Deck *Player::getHealth() const {
	return health;
}
