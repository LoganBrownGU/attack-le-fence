//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_GAME_H
#define ATTACK_LE_FENCE_GAME_H


#include <vector>
#include "Card.h"
#include "player/Player.h"

class Game {

public:
    void play();

    Game(std::vector<PlayerType> *players);
    ~Game();

private:
    std::vector<Card *> *unusedPile, *usedPile;
    std::vector<Player *> *players;
};


#endif //ATTACK_LE_FENCE_GAME_H
