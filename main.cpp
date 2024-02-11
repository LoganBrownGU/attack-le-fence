#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto deck = CardFactory::generateNormalDeck();
    //CardFactory::shuffleDeck(deck);
    CardFactory::printDeck(deck);


}
