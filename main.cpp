#include <iostream>
#include <vector>
#include "CardFactory.h"

int main() {
    auto cards = CardFactory::generateNormalDeck();

    for (const auto &card: *cards) {
        std::cout << card->toString() << std::endl;
    }
}
