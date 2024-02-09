//
// Created by logan on 09/02/24.
//

#ifndef ATTACK_LE_FENCE_IPLAYER_H
#define ATTACK_LE_FENCE_IPLAYER_H


#include <vector>

class Card;

class Player {

public:
    virtual Card playCard() = 0;

private:
    std::vector<Card> cards;

};


#endif //ATTACK_LE_FENCE_IPLAYER_H
