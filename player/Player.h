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

    virtual Player *actionOnPlayer(std::vector<Player *> *players) = 0;

    virtual void decideCards(std::vector<Card *> *cards) = 0;

    virtual bool useStashed() = 0;


    void stashCard(Card *card);

    Card *playStashed();

    bool hasStashed();

    [[nodiscard]] std::vector<Card *> *getShield() const;

    [[nodiscard]] std::vector<Card *> *getHealth() const;

    Player();
    ~Player();

protected:
    // IMPORTANT:   Player does not have ownership over any cards.
    //              vectors should never be replaced, only contents

    // vector of refs to Cards that make up the player's shield
    const std::vector<Card *> *shield;
    // vector of refs to Cards that make up the player's health
    const std::vector<Card *> *health;
    // ref to player's stashed card
    Card *stashedCard;
};


#endif //ATTACK_LE_FENCE_PLAYER_H
