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

Player *LocalCLIPlayer::actionOnPlayer(std::vector<Player *> vector) {
    return nullptr;
}

void LocalCLIPlayer::decideCards(std::vector<Card *> vector) {

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
