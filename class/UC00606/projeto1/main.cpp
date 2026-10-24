#include <iostream>
#include <string>
using namespace std;

int somar(int x, int y) {
	return x+y;
}

int subtrair(int x, int y) {
	return x-y;
}

int multiplicar(int x, int y) {
	return x*y;
}

int paridade(int x) {
	if (x%2==0) return true;
	return false;
}

int main() {
	cout << "\033[1mProjeto 1 - Calculadora com menu\033[0m\n\n";
	// Desenvolva um programa em C++ que apresente um menu com cinco opções.
	// O menu deverá voltar a aparecer após cada operação, até o utilizador escolher T para terminar.

	// MENU PRINCIPAL
	// A - Somar dois números inteiros
	// B - Subtrair dois números inteiros
	// C - Multiplicar dois números inteiros
	// D - Verificar se um número inteiro é par ou impar
	// T - Terminar o programa

	// REQUISITOS
	// - Utilize uma função própria para cada operação (somar, subtrair, multiplicar e verificar paridade).
	// - No main() apresente o menu, leia a opção e chame a função correspondente.
	// - Nas opções A, B e C, peça dois números inteiros e apreente o resultado. Na opção D, peça apenas um número.
	// - Aceite tanto maiúsculas como minúsculas.
	// - Se a opção não existir, apresente uma mensagem de erro e volte ao menu.
	// - Ao selecionar T, apresente uma mensagem de despedida e termine o programa.
	// - Não utilize arrays nem matrizes--

	char op;
	int n1,n2,n;

	do {
		cout << "A - Somar dois números inteiros\n";
		cout << "B - Subtrair dois números inteiros\n";
		cout << "C - Multiplicar dois números inteiros\n";
		cout << "D - Verificar se um número inteiro é par ou impar\n";
		cout << "T - Terminar o programa\n";
		cin >> op;

		switch(op) {
			case 'a':
			case 'A':
				cout << "Insira um número: ";
				cin >> n1;
				cout << "Insira outro número: ";
				cin >> n2;
				cout << somar(n1,n2) << "\n\n";
				break;

			case 'b':
			case 'B':
				cout << "Insira um número: ";
				cin >> n1;
				cout << "Insira outro número: ";
				cin >> n2;
				cout << subtrair(n1,n2) << "\n\n";
				break;

			case 'c':
			case 'C':
				cout << "Insira um número: ";
				cin >> n1;
				cout << "Insira outro número: ";
				cin >> n2;
				cout << multiplicar(n1,n2) << "\n\n";
				break;

			case 'd':
			case 'D':
				cout << "Insira um número: ";
				cin >> n;
				if (paridade(n)) cout << "Número é par\n\n";
				else cout << "Número é impar\n\n";
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