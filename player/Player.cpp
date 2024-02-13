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

Player::Player() {
    this->shield = new std::vector<Card *>;
    this->health = new std::vector<Card *>;
    this->stashedCard = nullptr;
}

Player::~Player() {
    delete this->health;
    delete this->shield;
}

bool Player::hasStashed() {
    return this->stashedCard;
}

std::vector<Card *> *Player::getShield() const {
    return const_cast<std::vector<Card *> *>(shield);
}

std::vector<Card *> *Player::getHealth() const {
    return const_cast<std::vector<Card *> *>(health);
}
