#include "game.h"
#include <map>

#ifndef __LOTTERY__
#define __LOTTERY__

using namespace std;

typedef map<int, Game> tp_game;

class Lottery {
public:
	Lottery(int n, int m);
	Lottery(int n, int m, int* matches, int matches_size);
	void add(Game game);
	void add(int id, const char* date, int numbers[], int k);
	Game* get(int id);
	void print_all();
	int getN();// probable numbers
	int getM();// possible numbers (n <= m)
	void zeroCounter();
	Game *getNext();
	int getSize();
	bool find(Numbers* n, int *matches, int k);
	bool find(Numbers* n);
	bool findPattern(Numbers* n);
	int* getMatches();
	int getMatchesSize();
	void setMatches(int* matches, int size);
private:
	int n_, m_, counter_;
	tp_game games;
	int* matches_;
	int matches_size_;
};

#endif /* __LOTTERY__ */
