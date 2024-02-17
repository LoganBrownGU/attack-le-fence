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
                    if (!player->hasStashed()) handleStash(player);
                    break;
            }
        }
    }
}

void Game::handleAttack(Player *player) {
    const auto &attackedPlayer = player->actionOnPlayer(players);
    bool useStashed = false;
    if (player->hasStashed()) useStashed = player->useStashed();
    const auto &attackingCard = this->unusedPile->back();
    Card *stashedCard = nullptr;
    this->unusedPile->pop_back();

    int health = CardFactory::totalValue(attackedPlayer->getHealth());
    health -= attackingCard->getValue();
    if (useStashed) {
        stashedCard = player->playStashed();
        health -= stashedCard->getValue();
    }

    // Now decide how to make up the new health
    std::vector<Card *> newHealth = std::vector<Card *>();  // cards to make up new health
    std::vector<Card *> oldCards = std::vector<Card *>();   // cards to be returned to used pile

    // Check if either attackingCard or stashedCard equal player's new health
    if (health == attackingCard->getValue()) {
        newHealth.push_back(attackingCard);
        if (stashedCard) oldCards.push_back(stashedCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    } else if (stashedCard && health == stashedCard->getValue()) {
        newHealth.push_back(stashedCard);
        oldCards.push_back(attackingCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    } else if (stashedCard && health == attackingCard->getValue() + stashedCard->getValue()) {
        newHealth.push_back(attackingCard);
        newHealth.push_back(stashedCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    }

    // If above doesn't work, then we know that stashed and attacking cards won't be used
    oldCards.push_back(attackingCard);
    if (stashedCard) oldCards.push_back(stashedCard);

    // Check all subsets of player's health
    int x = (int) attackedPlayer->getHealth()->size();
    for (int i = 0; i < (1 << x); i++) {
        auto set = std::vector<Card *>();
        for (int j = 0; j < x; j++) {
            if (!(i & (1 << j)))
                continue;
            set.push_back(attackedPlayer->getHealth()->at(j));
        }

        if (health == CardFactory::totalValue(&set)) {
            newHealth = set;
            cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
            return;
        }
    }

    // Try to use the used pile
    // Find all two value combos that could equal health
    auto pairs = std::vector<std::pair<int, int>>();
    for (int i = std::max(1, health - 13); i <= 13; i++)
        pairs.emplace_back(i, health - i);

    for (auto &pair: pairs) {
        auto indices = CardFactory::containsSubset(this->usedPile, &pair);
        if (indices.first == -1 || indices.second == -1) continue;

        newHealth.push_back(this->usedPile->at(indices.first));
        newHealth.push_back(this->usedPile->at(indices.second));
        this->usedPile->erase(this->usedPile->begin() + indices.first);
        this->usedPile->erase(this->usedPile->begin() + indices.second);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        break;
    }

    // Do the same to the unused pile
    for (auto pair: pairs) {
        auto indices = CardFactory::containsSubset(this->unusedPile, &pair);
        if (indices.first == -1 || indices.second == -1) continue;

        newHealth.push_back(this->unusedPile->at(indices.first));
        newHealth.push_back(this->unusedPile->at(indices.second));
        this->unusedPile->erase(this->unusedPile->begin() + indices.first);
        this->unusedPile->erase(this->unusedPile->begin() + indices.second);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        break;
    }
}

void Game::handleSwap(Player *player) {
    const auto &swappedPlayer = player->actionOnPlayer(players);
    auto newShield = this->unusedPile->back();
    this->unusedPile->pop_back();

    auto shield = swappedPlayer->getShield();
    // If new shield value matches current shield value
    if (CardFactory::totalValue(shield) == newShield->getValue()) {
        shield->push_back(newShield);
        return;
    }

    // Take old shield cards and put them in the used pile
    while (!shield->empty()) {
        this->usedPile->insert(this->usedPile->begin(), shield->back());
        shield->pop_back();
    }

    shield->push_back(newShield);
}

void Game::handleStash(Player *player) {
    player->stashCard(this->unusedPile->back());
    this->unusedPile->pop_back();
}

void Game::cleanUp(std::vector<Card *> *playerHealth, std::vector<Card *> *newHealth, std::vector<Card *> *oldCards) {

    // Take all cards that ARE in playerHealth, but NOT in newHealth, and add them to oldCards
    for (const auto &card: *playerHealth) {
        bool discovered;
        for (const auto &healthCard: *newHealth)
            if (card == healthCard) discovered = true;

        if (!discovered) oldCards->push_back(card);
    }

    // Remove all cards from player's health
    playerHealth->clear();
    // Add all cards from newHealth to player's health
    for (const auto &card: *newHealth)
        playerHealth->push_back(card);

    // Add all cards from oldCards to usedPile
    for (const auto &card: *oldCards)
        this->usedPile->push_back(card);
}
