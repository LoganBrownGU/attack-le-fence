//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_PLAYER_H
#define ATTACK_LE_FENCE_PLAYER_H


#include <vector>
#include "../Deck.h"

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

    virtual void decideCards(Deck *cards) = 0;

    virtual bool useStashed() = 0;

    // Place card in player's stash
    void stashCard(Card *card);

    // Removes player's stashed card and returns it
    Card *playStashed();

    // Returns true if player has a stashed card
    bool hasStashed();

    [[nodiscard]] Deck *getShield() const;

    [[nodiscard]] Deck *getHealth() const;

    Player();

    ~Player();

protected:
    // IMPORTANT:   Player does not have ownership over any cards.
    //              vectors should never be replaced, only contents

    // Deck of cards that makes up the player's shield
    Deck *const shield;
    // Deck of cards that makes up the player's healths
    Deck *const health;
    // ref to player's stashed card
    Card *stashedCard;
};


#endif //ATTACK_LE_FENCE_PLAYER_H
