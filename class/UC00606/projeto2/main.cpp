#include <iostream>
#include <string>
using namespace std;

double preco=0;
int entrada, saida, totalEntradas=0, totalSaidas=0;

double definirPreco(double p) {
	if (p>0) preco=p;
	return preco;
}

int registarEntrada(int e) {
	if (e>0) {
		entrada=e;
		totalEntradas=totalEntradas+entrada;
	}
	return totalEntradas;
}

int registarSaida(int s) {
	if (s>0 && totalEntradas-totalSaidas>0 && s<=totalEntradas-totalSaidas) {
		saida=s;
		totalSaidas=totalSaidas+saida;
	}
	return totalSaidas;
}

int main() {
	cout << "\033[1mProjeto 2 - Gestão de stock de um artigo\033[0m\n\n";
	// OBJETIVO
	// Desenvolva um programa em C++ para gerir o stock de uma pequena loja que comercializa apenas um artigo.
	// O programa deve registar entradas e saídas de unidades, consultar os totais acumulados e calcular o valor do stock.
	// Não é necessário guardar cada movimento individualmente.

	// MENU PRINCIPAL
	// A - Definir preço unitário
	// B - Registar entrada de unidades
	// C - Registar saída de unidades
	// D - Consultar total de entradas
	// E - Consultar total de saídas
	// F - Consultar stock atual
	// G - Consultar valor do stock
	// T - Terminar programa

	// FUNCIONAMENTO DAS OPÇÕES
	// A - Definir preço unitário: solicite um preço superior a zero. O preço pode ser alterado posteriormente.
	// B - Registar entrada de unidades: solicite uma quantidade inteira positiva e adicione-a ao stock. Atualize também o total acumulado de entradas.
	// C - Registar saída de unidades: solicite uma quantidade inteira positiva. A saída só é permitida se houver stock suficiente;
	// caso contrário, apresente uma mensagem e não altere os valores. Atualize o total acumulado de saídas.
	// D - Consultar total de entradas: apresente a quantidade total de unidades entradas desde o início do programa.
	// E - Consultar total de saídas: apresente a quantidade total de unidades saídas desde o início do programa.
	// F - Consultar stock atual: apresente o número de unidades disponíveis.
	// G - Consultar valor do stock: apresente stock atual x preço unitário. Se o preço não estiver definido apresente uma mensagem informativa.
	// T - Terminar programa: apresente uma mensagem de despedida e termine a execução.

	// REQUISITOS
	// - Utilize cin e cout; apresente repetidamente o menu com ciclo e trate as opções com switch ou if.
	// - Crie funções próprias para as operações principais; Utilize parâmetros e valores de retorno sempre que adequado.
	// - Valide os dados introduzidos, impeça quantidades negativas e nunca permita que o stock fique negativo.
	// - Aceite letras maiúsculas e minúsculas e apresente uma mensagem para opções inválidas.
	// - Utilize variáveis simples e acumuladoras; não utilize arrays, matrizes nem ficheiros.

	char op;
	double p;
	int in, out;
	
	do {
		cout << "A - Definir preço unitário\n";
		cout << "B - Registar entrada de unidades\n";
		cout << "C - Registar saída de unidades\n";
		cout << "D - Consultar total de entradas\n";
		cout << "E - Consultar total de saídas\n";
		cout << "F - Consultar stock atual\n";
		cout << "G - Consultar valor do stock\n";
		cout << "T - Terminar programa\n";
		cin >> op;

		switch(op) {
			case 'a':
			case 'A':
				cout << "Defina o preço unitário: ";
				cin >> p;
				cout << definirPreco(p) << "€\n\n";
				break;

			case 'b':
			case 'B':
				cout << "Entradas: ";
				cin >> in;
				cout << registarEntrada(in) << " entradas\n\n";
				break;

			case 'c':
			case 'C':
				cout << "Saídas: ";
				cin >> out;
				cout << registarSaida(out) << " saídas\n\n";
				break;

			case 'd':
			case 'D':
				cout << totalEntradas << " entradas\n\n";
				break;

			case 'e':
			case 'E':
				cout << totalSaidas << " saidas\n\n";
				break;

			case 'f':
			case 'F':
				cout << "Stock: " << totalEntradas-totalSaidas << "\n\n";
				break;

			case 'g':
			case 'G':
				if (preco>0) cout << "Valor do stock: " << (totalEntradas-totalSaidas)*preco << "€\n\n";
				else cout << "Erro: preço não definido!\n\n";
				break;

			case 't':
			case 'T':
				cout << "Adeus!\n";
				break;

			default:
				cout << "Insira uma opção válida!\n\n";
		}
	} while (op!='T' && op!='t');
}