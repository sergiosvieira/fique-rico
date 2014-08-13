#include "node.h"
#include "transfer-function.h"

double abs(double value) {
	return (value < 0) ? value * -1.0 : value;
}
/*
int main(int argc, char** argv) {
	StepFunction funcao_degrau;
	InputNode in_a(0),// bias
			in_b(1), in_c(2);
	OutputNode out_a(0);

	in_a.add_output_node(&out_a, 0.0);
	in_a.value = 1.0;

	in_b.add_output_node(&out_a, 0.0);
	in_c.add_output_node(&out_a, 0.0);

	//out_a.print_info();

	double expected[] = { 1, // Kepler
			0, // Beethove
			1, // Einstein
			0 // Bachn
			};

	double info[][2] = { { 0.0, 1.0 }, // Kepler
			{ 1.0, 1.0 }, // Beethoven
			{ 1.0, 0.0 }, // Einstein
			{ 0.0, 0.0 }//BACH
	};

	double error[] = { 0, 0, 0, 0 };

	//printf("Resultado da função de ativação: %.3f\n", out_a.get_total_weighted_input());
	//printf("Saída: %.3f\n", funcao_degrau.get_result(out_a.get_total_weighted_input()));

	double result = 0.0;
	double total = 0.0;
	double em = 1.0;

	while (em != 0.0) {

		for (int i = 0; i < 4; i++) {
			in_b.value = info[i][0];
			in_c.value = info[i][1];
			//out_a.print_info();

			double w = out_a.get_total_weighted_input(); // cálculo da função de ativação
			//printf("Resultado da função de ativação: %.3f\n", w);
			result = funcao_degrau.get_result(w);
			//printf("Saída: %.3f Esperado: %.3f\n", result, expected[i]);
			error[i] = expected[i] - result;
			total += abs(error[i]);
			//printf("Erro: %3.f\n", error[i]);
			out_a.update_weights(error[i]);

			printf("\n");
		}

		em = total / 4.0;
		printf("Erro médio: %.3f\n", em);
		total = 0.0;
	}

	return 0;
}
*/
