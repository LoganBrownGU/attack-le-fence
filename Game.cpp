//
// Created by logan on 10/02/24.
//

#include "Game.h"
#include "CardFactory.h"

Game::Game(std::vector<PlayerType> *players) {
    this->unusedPile = CardFactory::generateNormalDeck();
    this->usedPile = new std::vector<Card *>;

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

Game::~Game() {
    delete this->usedPile;
    delete this->unusedPile;
    delete this->players;
}

void Game::play() {
    // Copy players into active players
    auto activePlayers = std::vector<Player *>();
    for (const auto &player: *this->players)
        activePlayers.push_back(player);

    while (activePlayers.size() > 1) {
        for (const auto &player: activePlayers) {
            auto action = player->play();

            switch (action) {
                case ATTACK:
                    handleAttack(player);
                    break;
                case SWAP:
                    handleSwap(player);
                    break;
                case STASH:
                    handleStash(player);
                    break;
            }
        }
    }
}

void Game::handleAttack(Player *player) {
    const auto &attackedPlayer = player->actionOnPlayer(players);

}
