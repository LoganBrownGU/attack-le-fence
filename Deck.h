//
// Created by logan on 17/02/24.
//

#ifndef ATTACK_LE_FENCE_DECK_H
#define ATTACK_LE_FENCE_DECK_H


#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card *> * const cards;

public:
    Deck();

    virtual ~Deck();

    // Takes n cards from the deck and returns them as a vector
    std::unique_ptr<std::vector<Card *>> deal(int n);
    // Randomises the order of the deck
    void shuffle();
    // Returns the sum of all the values of the cards in the deck
    int totalValue();
    // Returns card at position i
    Card *at(int i);
    // Returns card at the top of the deck (if it was facing upwards) and removes it from the deck
    Card *top();
    // Returns card at the bottom of the deck (if it was facing upwards) and removes it from the deck
    Card *bottom();
    // Removes the card at index i and returns it
    Card *pop(int i);
    // Checks if the deck is empty
    bool isEmpty();
    // Returns a string representation of the deck
    std::string toString();
};


#endif //ATTACK_LE_FENCE_DECK_H
