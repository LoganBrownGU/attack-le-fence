#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto cards = CardFactory::generateNormalDeck();

    for (Card *card: *cards) {
        std::cout << card->toString() << std::endl;
    }
}
