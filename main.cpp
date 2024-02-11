#include <iostream>
#include <vector>
#include "CardFactory.h"
#include "player/LocalCLIPlayer.h"

int main() {
    auto deck = CardFactory::generateNormalDeck();
    //CardFactory::shuffleDeck(deck);
    CardFactory::printDeck(deck);

    auto player1 = new LocalCLIPlayer();
    player1->decideCards(CardFactory::dealCards(deck, 3).get());
}
