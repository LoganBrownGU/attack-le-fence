//
// Created by logan on 08/02/24.
//

#ifndef ATTACK_LE_FENCE_CARD_H
#define ATTACK_LE_FENCE_CARD_H

#include <memory>

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS};

class Card {

private:
    const int value;
    const std::unique_ptr<Suit> *suit;

public:

    Card(int value, std::unique_ptr<Suit> *suit);

    [[nodiscard]] int getValue() const;

    [[nodiscard]] std::unique_ptr<Suit> *getSuit() const;
};


#endif //ATTACK_LE_FENCE_CARD_H
