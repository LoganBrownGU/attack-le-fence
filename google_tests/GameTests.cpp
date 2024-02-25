//
// Created by logan on 25/02/24.
//

#include <gtest/gtest.h>
#include "../Deck.h"

class DeckFixture : public ::testing::Test {
protected:
    Deck *deck;

    virtual void setUp() {
        deck = new Deck();
    }

    virtual void tearDown() {
        delete deck;
    }
};

TEST_F(DeckFixture, DeckSize) {
    deck->place_top(new Card(1, Suit::DIAMONDS));
    deck->place_top(new Card(1, Suit::DIAMONDS));
    deck->place_top(new Card(1, Suit::DIAMONDS));
    deck->place_top(new Card(1, Suit::DIAMONDS));

    EXPECT_EQ(deck->size(), 4);
}