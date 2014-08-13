#include "lib/read-result.h"
#include "lib/generator-factory.h"
#include "lib/pf-based.h"
#include "lib/utils.h"

#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
	int guesses = 0;

	if (argc < 2) {
		printf("Fique Rico 1.0 (c) 2011 - sergiosvieira@gmail.com\nusage: ./fique-rico <# of guesses>\n");
	} else {
		guesses = atoi(argv[1]);
	}

	ReadResult r;
	Lottery *lf = r.read("data/lotofacil.dat", 15, 25);
	//Lottery *lm = r.read("data/lotomania.dat", 20, 100);
	Lottery *aux = lf;


	GeneratorFactory gen_fac(aux);
	//Generator* gen_pt = gen_fac.createPatternBased();
	Generator* gen_rpt = gen_fac.createRndPatternBased();
	Generator* gen_rn = gen_fac.createRndBased();

	int past = 60;
	int m[] = {1, 3, 4, 7, 10, 13, 14, 15, 16, 17, 18, 20, 21, 23, 24};
	int n[] = {1,2,4,6,7,11,12,14,15,16,18,20,21,24,25};
	//int n[] = {8, 11, 17, 21, 22, 34, 40, 41, 46, 48, 50, 54, 58, 60, 68, 75, 77, 80, 92, 100};
	Numbers last_result_lf(n, 15);
	Numbers before_last(m, 15);
	//Numbers** numbers_pt = gen_pt->generate(aux->getSize() - past, guesses);
	Numbers** numbers_rpt = gen_rpt->generate(aux->getSize() - past, guesses);
	Numbers** numbers_rn = gen_rn->generate(aux->getSize() - past, guesses);
	Numbers** aux_numbers = numbers_rpt;

	int size = aux->getN() + 1;

	int* hits_frequency_rn = new int[size];
	int* hits_frequency = new int[size];

	for (int i = 0; i < size; i++) {
		hits_frequency_rn[i] = 0;
		hits_frequency[i] = 0;
	}
	int counter = 0;
	for (int i = 0; i < guesses; i++) {
		int hits_rn = numbers_rn[i]->match(&before_last);
		//hits_frequency_rn[hits_rn]++;
		int hits = aux_numbers[i]->match(&before_last);
		//hits_frequency[hits]++;
		if (hits_rn == 8 || hits_rn == 9 || hits_rn == 10) {
			counter++;
			numbers_rn[i]->print();
			int h = numbers_rn[i]->match(&last_result_lf);
			hits_frequency_rn[h]++;
			printf("hits with last: %d\n",h);
		}
		if (hits == 8 || hits == 9 || hits == 10) {
			counter++;
			aux_numbers[i]->print();
			int h = aux_numbers[i]->match(&last_result_lf);
			hits_frequency[h]++;
			printf("hits with last: %d\n", h);
		}
	}

	printf("Jogos = %d\n", counter);


	printf("F\tA\tR\n");
	double gain = 0.0;
	double gain_rn = 0.0;
	for (int i = 0; i < size; i++) {
		printf("%d\t%d\t%d\n", i, hits_frequency[i], hits_frequency_rn[i]);
		//printf("%d\t%d\n", i, hits_frequency_rn[i]);
		switch(i) {
		case 11:
			gain += hits_frequency[i] * 2.5;
			gain_rn += hits_frequency_rn[i] * 2.5;
			break;
		case 12:
			gain += hits_frequency[i] * 5.0;
			gain_rn += hits_frequency_rn[i] * 5.0;
			break;
		case 13:
			gain += hits_frequency[i] * 12.5;
			gain_rn += hits_frequency_rn[i] * 12.5;
			break;
		case 14:
			gain += hits_frequency[i] * 1928.08;
			gain_rn += hits_frequency_rn[i] * 1928.08;
			break;
		case 15:
			gain += hits_frequency[i] * 1008663.25;
			gain_rn += hits_frequency_rn[i] * 1008663.25;
			break;
		}
	}

	printf("custo: %f ganho_rn:%f ganho:%f total:%f\n", counter * 1.25, gain_rn, gain, (gain_rn + gain) - (counter * 1.25));

	delete aux;

	return 0;
}
