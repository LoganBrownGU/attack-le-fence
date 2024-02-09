//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_PLAYER_H
#define ATTACK_LE_FENCE_PLAYER_H


#include <vector>

class Card;

enum Action {
    ATTACK,
    SWAP,
    STASH
};

class Player {

public:
    virtual Action play() = 0;
    virtual Player *actionOnPlayer(std::vector<Player *>) = 0;

    void stashCard(Card *card);
    Card *playStashed();

private:
    // IMPORTANT: Player should not have ownership over any cards.
    std::vector<Card *> shield;
    std::vector<Card *> health;
    Card *stashedCard;
};


#endif //ATTACK_LE_FENCE_PLAYER_H
