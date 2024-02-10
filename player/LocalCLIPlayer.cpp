//
// Created by logan on 10/02/24.
//

#include <iostream>
#include "LocalCLIPlayer.h"
#include "../Card.h"

Action LocalCLIPlayer::play() {
    this->printCards();

    while (true) {
        std::cout << "What would you like to do? (h for options)" << std::endl;

        std::string input;
        std::cin >> input;
        if (input == "attack")  return ATTACK;
        if (input == "swap")    return SWAP;
        if (input == "stash")   return STASH;

        if (input == "h")
            std::cout << "attack, swap, or stash" << std::endl;
    }
}

Player *LocalCLIPlayer::actionOnPlayer(std::vector<Player *> players) {
    return nullptr;
}

void LocalCLIPlayer::decideCards(std::vector<Card *> cards) {
    std::cout << "Your cards are: ";
    int i = 1;
    for (const auto &card: cards)
        std::cout << std::to_string(i++) << ": " << card->toString() << std::endl;

    while (this->shield->empty()) {
        std::string input;
        std::cout << "\nEnter the number(s) of the card(s) for your shield: ";
        std::cin >> input;
        size_t delimPos = input.find(',');

        int card1, card2 = -1;
        try {
            if (delimPos == std::string::npos) card1 = std::stoi(input);
            else {
                card1 = std::stoi(input.substr(delimPos));
                card2 = std::stoi(input.substr(delimPos, input.length() - 1));
            }
        } catch (std::exception &e) {
            std::cout << "Make sure you enter two integers, seperated by ','\n";
        }

        if (card1 > 3 || card1 < 1) continue;
        this->shield->push_back(cards.at(card1));
        if (card2 > 3 || card2 < 1) continue;
        this->shield->push_back(cards.at(card2));
    }

    //todo add other cards to health
    // todo change argument to pointer
}

void LocalCLIPlayer::printCards() {
    std::cout << "shield: ";
    for (Card *card: *this->shield)
        std::cout << card->toString() << " | ";

    std::cout << "\nhealth";
    for (Card *card: *this->health)
        std::cout << card->toString() << " | ";

    std::cout << "\nstashed card: " << (this->stashedCard ? "no" : "yes") << std::endl;
}
