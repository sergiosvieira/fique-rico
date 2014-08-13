#include <cstring>
#include <iostream>

#ifndef __GAME__
#define __GAME__

class Numbers;

class Numbers {
public:
	Numbers();
	Numbers(int numbers[], int k);
	void print();
	void report();
	void setNumbers(int numbers[], int k);
	void zeroCounter();
	int getNext();
	int match(Numbers* other);
	void setFitness(double fitness);
	double getFitness();
	int getSize();
	int* getNumbers();
private:
	int *numbers_;
	int size_;
	int even_;
	int counter_;
	double fitness_;
};

class Game {
public:
	Game();
	Game(int id, std::string date, Numbers *numbers);
	void print();
	int getId();
	void setGame(int id, std::string date, Numbers *numbers);
	Numbers* getNumbers();
	Numbers* getPattern();
private:
	int id_;
	std::string date_;
	Numbers* numbers_;
	Numbers* pattern_;
};

#endif /* __GAME__ */
