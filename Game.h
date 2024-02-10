//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_GAME_H
#define ATTACK_LE_FENCE_GAME_H


#include <vector>
#include "Card.h"
#include "Player.h"

class Game {

public:
    void init(std::vector<PlayerType> players);

    void play();

private:
    std::vector<Card *> unusedPile, usedPile;
};


#endif //ATTACK_LE_FENCE_GAME_H
