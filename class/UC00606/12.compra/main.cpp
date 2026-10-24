#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m12. Cálculo de uma compra\033[0m\n\n";
	// Leia o nome de um produto, o preço unitário e a quantidade comparada. Calcule e apresente o valor total de compra--

	string produto;
	double preco = 0, total = 0;
	int quantidade = 0;

	cout << "Insira o nome do produto: ";
	cin >> produto;
	cout << "Insira o preço unitário: ";
	cin >> preco;
	cout << "Insira a quantidade: ";
	cin >> quantidade;

	total = preco * quantidade;
	cout << "\nValor total da compra: " << total << "€\n";
}