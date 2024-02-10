//
// Created by logan on 10/02/24.
//

#include "Game.h"
#include "CardFactory.h"

Game::Game(std::vector<PlayerType> *players) {
    this->unusedPile = CardFactory::generateNormalDeck();
    this->usedPile = std::vector<std::unique_ptr<Card>>();

    // todo implement concrete players and write switches
    for (PlayerType playerType: *players) {
        switch (playerType) {
            case BOT:
                break;
            case LOCAL_CLI:
                break;
            case REMOTE_CLI:
                break;
        }
    }
}
