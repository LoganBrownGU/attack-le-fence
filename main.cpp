#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto cards = CardFactory::generateNormalDeck();

    CardFactory::printDeck(cards);
}
