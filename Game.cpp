//
// Created by logan on 10/02/24.
//

#include "Game.h"
#include "CardFactory.h"

Game::Game(std::vector<PlayerType> *players) {
    this->unusedPile = CardFactory::generateNormalDeck();
    this->usedPile = new Deck();

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
    const auto &attackingCard = this->unusedPile->pop_bottom();
    Card *stashedCard = nullptr;

    int health = attackedPlayer->getHealth()->totalValue();
    health -= attackingCard->getValue();
    if (useStashed) {
        stashedCard = player->playStashed();
        health -= stashedCard->getValue();
    }

    // Now decide how to make up the new health
    auto newHealth = Deck();  // cards to make up new health
    auto oldCards = Deck();   // cards to be returned to used pile

    // Check if either attackingCard or stashedCard equal player's new health
    if (health == attackingCard->getValue()) {
        newHealth.place_top(attackingCard);
        if (stashedCard) oldCards.place_top(stashedCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    } else if (stashedCard && health == stashedCard->getValue()) {
        newHealth.place_top(stashedCard);
        oldCards.place_top(attackingCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    } else if (stashedCard && health == attackingCard->getValue() + stashedCard->getValue()) {
        newHealth.place_top(attackingCard);
        newHealth.place_top(stashedCard);
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    }

    // If above doesn't work, then we know that stashed and attacking cards won't be used
    oldCards.place_top(attackingCard);
    if (stashedCard) oldCards.place_top(stashedCard);

    // Check all subsets of player's health
    int x = (int) attackedPlayer->getHealth()->size();
    for (int i = 0; i < (1 << x); i++) {
        auto set = Deck();
        for (int j = 0; j < x; j++) {
            if (!(i & (1 << j)))
                continue;
            set.place_top(attackedPlayer->getHealth()->at(j));
        }

        if (health == set.totalValue()) {
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

        newHealth.place_top(this->usedPile->pop(indices.first));
        newHealth.place_top(this->usedPile->pop(indices.second));
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    }

    // Do the same to the unused pile
    for (auto pair: pairs) {
        auto indices = CardFactory::containsSubset(this->unusedPile, &pair);
        if (indices.first == -1 || indices.second == -1) continue;

        newHealth.place_top(this->unusedPile->pop(indices.first));
        newHealth.place_top(this->unusedPile->pop(indices.second));
        cleanUp(attackedPlayer->getHealth(), &newHealth, &oldCards);
        return;
    }
}

void Game::handleSwap(Player *player) {
    const auto &swappedPlayer = player->actionOnPlayer(players);
    auto newShield = this->unusedPile->pop_bottom();

    auto shield = swappedPlayer->getShield();
    // If new shield value matches current shield value
    if (shield->totalValue() == newShield->getValue()) {
        shield->place_top(newShield);
        return;
    }

    // Take old shield cards and put them in the used pile
    while (!shield->isEmpty()) {
        this->usedPile->place_top(shield->pop_top());
    }

    shield->place_top(newShield);
}

void Game::handleStash(Player *player) {
    player->stashCard(this->unusedPile->pop_bottom());
}

void Game::cleanUp(Deck *playerHealth, Deck *newHealth, Deck *oldCards) {

    // Take all cards that ARE in playerHealth, but NOT in newHealth, and add them to oldCards
    for (const auto &card: *playerHealth) {
        bool discovered;
        for (const auto &healthCard: *newHealth)
            if (card == healthCard) discovered = true;

        if (!discovered) oldCards->place_top(card);
    }

    // Remove all cards from player's health
    playerHealth->clear();
    // Add all cards from newHealth to player's health
    for (const auto &card: *newHealth)
        playerHealth->place_top(card);

    // Add all cards from oldCards to usedPile
    for (const auto &card: *oldCards)
        this->usedPile->place_top(card);
}
