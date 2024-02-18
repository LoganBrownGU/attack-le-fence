//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_GAME_H
#define ATTACK_LE_FENCE_GAME_H


#include <vector>
#include "Card.h"
#include "player/Player.h"
#include "Deck.h"

class Game {

public:
    void play();

    Game(std::vector<PlayerType> *players);
    ~Game();

private:
    Deck *unusedPile, *usedPile;
    std::vector<Player *> *players;
    void handleAttack(Player *player);
    void handleSwap(Player *player);
    void handleStash(Player *player);
    void cleanUp(Deck *playerHealth, Deck *newHealth, Deck *oldCards);
};


#endif //ATTACK_LE_FENCE_GAME_H
