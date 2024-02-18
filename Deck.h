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
    ~Deck();

    // Takes n cards from the deck and returns them as a vector
    std::unique_ptr<std::vector<Card *>> deal(int n);
    // Returns the sum of all the values of the cards in the deck
    int totalValue();
    // Returns card at position i
    Card *at(int i);
    // Returns card at the top of the deck (if it was facing upwards) and removes it from the deck
    Card *pop_top();
    // Returns card at the bottom of the deck (if it was facing upwards) and removes it from the deck
    Card *pop_bottom();
    // Removes the card at index i and returns it
    Card *pop(int i);
    // Checks if the deck is clear
    bool isEmpty();
    // Returns number of cards in deck
    size_t size();
    // Returns a string representation of the deck
    std::string toString();
    // Randomises the order of the deck
    void shuffle();
    // Places card on top of deck
    void place_top(Card *card);
    // Places card on bottom of deck
    void place_bottom(Card *card);
    // Empties deck
    void clear();

    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Card *;
        using pointer           = Card **;  // or also value_type*
        using reference         = Card *&;  // or also value_type&

        Iterator(int index, std::vector<Card *> *cards) : index(index), cards(cards) {}

        reference operator*() const { return cards->at(index); }
        pointer operator&() { return &cards->at(index); }

        Iterator &operator++() { index++; return *this; }

        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator &a, const Iterator &b) { return (a.index == b.index) && (a.cards == b.cards); }
        friend bool operator!= (const Iterator &a, const Iterator &b) { return (a.index != b.index) && (a.cards == b.cards); }

    private:
        std::vector<Card *> *cards;
        int index;
    };

    // Returns start of cards
    Iterator begin()    { return {0, cards}; }
    // Returns element after end of cards
    Iterator end()      { return {static_cast<int>(cards->size()), cards}; }
};


#endif //ATTACK_LE_FENCE_DECK_H
