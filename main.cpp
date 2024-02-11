#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto deck = CardFactory::generateNormalDeck();
    //CardFactory::shuffleDeck(deck);
    CardFactory::printDeck(deck);

    CardFactory::printDeck(CardFactory::dealCards(deck, 3).get());
    CardFactory::printDeck(deck);
}
