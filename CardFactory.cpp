//
// Created by logan on 09/02/24.
//

#include "CardFactory.h"

#include <memory>
#include <random>
#include <iostream>

Deck *CardFactory::generateNormalDeck() {
	Deck *deck = new Deck();

	for (const auto e: Suit::All) {
		for (int i = 1; i <= 13; i++)
			deck->place_top(new Card(i, e));
	}

	return deck;
}

std::pair<int, int> CardFactory::containsSubset(Deck *set, std::pair<int, int> *subset) {
	int idxFirst = -1, idxSecond = -1;

	for (int i = 0; i < set->size(); i++) {
		if (subset->first == set->at(i)->getValue()) idxFirst = i;
		else if (subset->second == set->at(i)->getValue()) idxSecond = i;

		if (idxFirst != -1 && idxSecond != -1) break;
	}

	return std::pair{idxFirst, idxSecond};
}
