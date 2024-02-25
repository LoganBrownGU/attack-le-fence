//
// Created by logan on 25/02/24.
//

#include "lib/googletest/include/gtest/gtest.h"
#include "../Deck.h"

TEST(AbsoluteGameTestSuite, ExampleDeck) {
    Deck deck;
    deck.place_top(new Card(1, Suit::DIAMONDS));
    deck.place_top(new Card(1, Suit::DIAMONDS));
    deck.place_top(new Card(1, Suit::DIAMONDS));
    deck.place_top(new Card(1, Suit::DIAMONDS));

    EXPECT_EQ(deck.size(), 4);
}