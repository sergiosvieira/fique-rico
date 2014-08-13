#include "game.h"
#include "utils.h"
#include <cstdio>

/* NUMBERS */

Numbers::Numbers(int numbers[], int k) {
	setNumbers(numbers, k);
}

Numbers::Numbers() {
	size_ = 0;
	even_ = 0;
	counter_ = 0;
	fitness_ = 0.0;
}

void Numbers::setNumbers(int numbers[], int k) {
	numbers_ = numbers;
	size_ = k;
	counter_ = 0;
	for (int i = 0; i < size_; i++) {
		if (numbers_[i] % 2 == 0) {
			even_++;
		}
	}
}

void Numbers::print() {
	printf("[");
	for (int i = 0; i < size_; i++) {
		printf("%d", numbers_[i]);
		if (i < size_ - 1) {
			printf(" ");
		}
	}
	printf("]\n");
}

void Numbers::report() {
	print();
	printf("\tN. Pares: %d N.Ímpares: %d\n\tTamanho: %d\n", even_,
			size_ - even_, size_);
}

void Numbers::zeroCounter() {
	counter_ = 0;
}

int Numbers::getNext() {
	if (counter_ < size_) {
		int result = numbers_[counter_];
		counter_++;
		return result;
	} else {
		zeroCounter();
		return -1;
	}
}

int Numbers::match(Numbers* other) {
	int result = 0;

	int value = 0;

	while ((value = other->getNext()) != -1) {
		for (int i = 0; i < size_; i++) {
			if (value == numbers_[i]) {
				result++;
			}
		}
	}

	return result;
}

void Numbers::setFitness(double fitness) {
	fitness_ = fitness;
}

double Numbers::getFitness() {
	return fitness_;
}

int Numbers::getSize() {
	return size_;
}

int* Numbers::getNumbers() {
	return numbers_;
}


/* GAME */

Game::Game(int id, std::string date, Numbers *numbers) {
	setGame(id, date, numbers);
}

Game::Game() {
}

void Game::print() {
	printf("%d %s ", id_, date_.c_str());
	numbers_->print();
}

int Game::getId() {
	return id_;
}

void Game::setGame(int id, std::string date, Numbers *numbers) {
	id_ = id;
	date_ = date;
	numbers_ = numbers;
	pattern_ = (Numbers*)pattern(numbers_);
}

Numbers* Game::getNumbers() {
	return numbers_;
}

Numbers* Game::getPattern() {
	return pattern_;
}
