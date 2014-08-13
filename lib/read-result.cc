/*
 * read-result.cc
 *
 *  Created on: 12/08/2011
 *      Author: sergio
 */

#include "read-result.h"
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "game.h"
#include "lottery.h"

ReadResult::ReadResult() {

}

Lottery *ReadResult::read(const char *filename, int n, int m) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		printf("File not found!\n");
		return NULL;
	}
	std::string buffer;

	Lottery *lottery = new Lottery(n, m);
	while (getline(file, buffer)) {
		//std::cout << buffer << std::endl;
		char *token = NULL;
		//char str[] = "1 2 3 4 45 534 212 3 2 413 2";
		char *str = new char[buffer.size() + 1];
		std::strcpy(str, buffer.c_str());
		char del[] = " ";
		token = strtok(str, del);

		int counter, i;
		counter = 0;
		i = 0;
		int *aux = new int[n];

		std::string date;
		int id;

		while (token != NULL) {
			char tmp[13];
			sscanf(token, "%s", tmp);
			switch (counter % 3) {
			case 0:
				id = atoi(tmp);
				counter++;
				break;
			case 1:
				date = string(tmp);
				counter++;
				break;
			case 2:
				aux[i] = atoi(tmp);
				i++;
				if (i >= n) {
					i = 0;
					counter = 0;
					lottery->add(id, date.c_str(), aux, n);
				}
				break;
			}
			token = strtok(NULL, del);
		}
	}
	return lottery;
}

Lottery* ReadResult::read(const char *filename, int n, int m, int* matches, int matches_size) {
	Lottery* result = read(filename, n, m);
	return result;
}
