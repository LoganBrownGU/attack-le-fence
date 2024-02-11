#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto deck = CardFactory::generateNormalDeck();

    CardFactory::printDeck(deck);
    CardFactory::shuffleDeck(deck);
    CardFactory::printDeck(deck);
}
