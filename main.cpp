#include <vector>
#include "CardFactory.h"
#include "player/LocalCLIPlayer.h"

int main() {
    auto deck = CardFactory::generateNormalDeck();
    //CardFactory::shuffle(deck);
    CardFactory::printDeck(deck);

    auto player1 = new LocalCLIPlayer();
    player1->decideCards(CardFactory::dealCards(deck, 3).get());
    auto action = player1->play();
    if (action == STASH) player1->stashCard(deck->back());
    player1->play();
}
