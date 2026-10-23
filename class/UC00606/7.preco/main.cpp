#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m7. Preço de três unidades\033[0m\n\n";

	double preco;

	cout << "Insira o preço unitário: ";
	cin >> preco;

	cout << "3 unidades custam: " << preco*3 << "€\n";
}