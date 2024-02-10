//
// Created by logan on 10/02/24.
//

#ifndef ATTACK_LE_FENCE_LOCALCLIPLAYER_H
#define ATTACK_LE_FENCE_LOCALCLIPLAYER_H

#include "Player.h"

class LocalCLIPlayer : public Player {
public:
    Action play() override;

    Player *actionOnPlayer(std::vector<Player *> vector) override;

    void decideCards(std::vector<Card *> vector) override;

private:
    void printCards();
};


#endif //ATTACK_LE_FENCE_LOCALCLIPLAYER_H