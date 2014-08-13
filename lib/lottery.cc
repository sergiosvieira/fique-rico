#include "lottery.h"

Lottery::Lottery(int n, int m) {
	n_ = n;
	m_ = m;
	counter_ = 0;
}

Lottery::Lottery(int n, int m, int* matches, int matches_size) {
	Lottery(n, m);
	matches = matches;
	matches_size_ = matches_size;
}

void Lottery::add(Game game) {
	games[game.getId()] = game;
}

void Lottery::add(int id, const char* date, int numbers[], int k) {
	Numbers *aux = new Numbers(numbers, k);
	Game game(id, date, aux);
	add(game);
}

Game* Lottery::get(int id) {
	return &games[id];
}

void Lottery::print_all() {
	for (tp_game::iterator it = games.begin(); it != games.end(); it++) {
		(*it).second.print();
	}
}

int Lottery::getN() {
	return n_;
}

int Lottery::getM() {
	return m_;
}

void Lottery::zeroCounter() {
	counter_ = 0;
}

Game *Lottery::getNext() {
	if (counter_ < games.size()) {
		Game *result = &games[counter_ + 1];
		counter_++;
		return result;
	} else {
		counter_ = 0;
		return NULL;
	}
}

int Lottery::getSize() {
	return games.size();
}

bool Lottery::find(Numbers* n, int *matches, int k) {
	Game* g = NULL;

	while ((g = getNext()) != NULL) {
		for (int i = 0; i < k; i++) {
			if (g->getNumbers()->match(n) == matches[i]) {
				return true;
			}
		}
	}

	return false;
}

bool Lottery::find(Numbers* n) {
	Game* g = NULL;

	while ((g = getNext()) != NULL) {
		int hits = g->getNumbers()->match(n);
		if (hits == n->getSize()) {
			return true;
		}
	}

	return false;
}
bool Lottery::findPattern(Numbers* n) {
	Game* g = NULL;
	while ((g = getNext()) != NULL) {
		int hits = g->getPattern()->match(n);
		if (hits == n->getSize()) {
			return true;
		}
	}
	return false;
}

int* Lottery::getMatches() {
	return matches_;
}

int Lottery::getMatchesSize() {
	return matches_size_;
}

void Lottery::setMatches(int* matches, int size) {
	matches_ = matches;
	matches_size_ = size;
}
