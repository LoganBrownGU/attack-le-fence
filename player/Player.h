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

enum PlayerType {
    BOT,
    LOCAL_CLI,
    REMOTE_CLI
};

class Player {

public:
    virtual Action play() = 0;

    virtual Player *actionOnPlayer(std::vector<Player *>) = 0;

    virtual void decideCards(std::vector<Card *>) = 0;


    void stashCard(Card *card);

    Card *playStashed();

    Player();
    ~Player();

protected:
    // IMPORTANT: Player should not have ownership over any cards.
    std::vector<Card *> *shield;
    std::vector<Card *> *health;
    Card *stashedCard;
};


#endif //ATTACK_LE_FENCE_PLAYER_H
