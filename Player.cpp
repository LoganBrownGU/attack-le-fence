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
