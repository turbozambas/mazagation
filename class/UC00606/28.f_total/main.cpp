#include <iostream>
#include <string>
using namespace std;

double calcularTotal(double preco, int quantidade) {
	return preco*quantidade;
}

int main() {
	cout << "\033[1m28. Calcular o preço total\033[0m\n\n";
	// Crie uma função double calcularTotal(double preco, int quantidade) que devolva o produto do preço pela quantidade.
	// No main(), leia os dois valores e apresente o total--

	double p;
	int q;

	cout << "Insira o preço: ";
	cin >> p;
	cout << "Insira a quantidade: ";
	cin >> q;

	cout << "Total: " << calcularTotal(p,q) << "€\n";
}