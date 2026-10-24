#include <iostream>
#include <string>
using namespace std;

int quadrado(int numero) {
	return numero*numero;
}

int main() {
	cout << "\033[1m27. Calcular o quadrado\033[0m\n\n";
	// Crie uma função int quadrado(int numero) que devolva o quadrado de um inteiro. No main(), leia o número e apresente o resultado--

	int n;

	cout << "Insira um número: ";
	cin >> n;

	cout << quadrado(n) << "\n";
}