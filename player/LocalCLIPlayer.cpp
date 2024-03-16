//
// Created by logan on 10/02/24.
//

#include <iostream>
#include "LocalCLIPlayer.h"
#include "../Card.h"
#include "../CardFactory.h"

Action LocalCLIPlayer::play() {
    this->printCards();

    while (true) {
        std::cout << "What would you like to do? (h for options)" << std::endl;

        std::string input;
        std::cin >> input;
        if (input == "attack")                      return ATTACK;
        if (input == "swap")                        return SWAP;
        if (input == "stash" && !this->stashedCard) return STASH;

        if (input == "h")
            std::cout << "attack, swap" << (this->stashedCard ? "" : ", stash") << std::endl;
    }
}

Player *LocalCLIPlayer::actionOnPlayer(std::vector<Player *> *players) {
    Player *player = nullptr;

    while (!player) {
        std::cout << "Which player do you want to perform the action on? (1-" << players->size() << "): ";
        std::string input;
        std::cin >> input;

        int index;
        try {
            index = std::stoi(input);
        } catch (std::exception &e) {
            continue;
        }

        if (index > players->size() || index < 1) continue;
        player = players->at(index - 1);
    }

    return player;
}

void LocalCLIPlayer::decideCards(Deck *cards) {
    std::cout << "Your cards are: \n";
    for (int i = 0; i < cards->size(); i++)
        std::cout << std::to_string(i + 1) << ": " << cards->at(i)->toString() << std::endl;

    while (this->shield->isEmpty()) {
        std::string input;
        std::cout << "\nEnter the number(s) of the card(s) for your shield: ";
        fflush(stdout);
        std::cin >> input;
        size_t delimPos = input.find(',');

        int card1, card2 = -1;
        try {
            if (delimPos == std::string::npos) card1 = std::stoi(input);
            else {
                card1 = std::stoi(input.substr(0, delimPos));
                card2 = std::stoi(input.substr(delimPos + 1));
            }
        } catch (std::exception &e) {
            std::cout << "Make sure you enter two integers, seperated by ','\n";
        }

        if (card1 > 3 || card1 < 1 || card2 > 3 || card2 < 1) continue;
        card1 -= 1;
        card2 -= 1;
        if (card1 > card2) {
            this->shield->place_top(cards->pop(card1));
            this->shield->place_top(cards->pop(card2));
        } else if (card2 > card1) {
            this->shield->place_top(cards->pop(card2));
            this->shield->place_top(cards->pop(card1));
        } else {
            this->shield->place_top(cards->pop(card1));
        }
    }

    // Add the rest of the cards to health
    for (const auto &card: *cards)
        this->health->place_top(card);

    std::cout << "Your setup is: \n";
    printCards();
    std::cout << "\n";
}

bool LocalCLIPlayer::useStashed() {
    while (true) {
        std::cout << "Do you want to use your stashed card? (y/n): ";
        std::string input;
        std::cin >> input;

        if (input == "y") return true;
        if (input == "n") return false;
    }
}

void LocalCLIPlayer::printCards() {
    const std::string cardBack = "|+-+-+-+-+-+|";

    std::cout << "shield: \n" << this->shield->toString() << std::endl;

    std::cout << "health: \n" << this->health->toString() << std::endl;

    std::cout << "stashed card: " << (this->stashedCard ? cardBack : "no") << std::endl;
}
