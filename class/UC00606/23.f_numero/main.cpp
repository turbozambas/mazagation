#include <iostream>
#include <string>
using namespace std;

void mostrarNumero(int numero) {
	cout << numero << "\n";
}

int main() {
	cout << "\033[1m23. Apresentar um número\033[0m\n\n";
	// Crie uma função void mostrarNumero(int numero) que apresente o número recebido. No main(), leia um número inteiro e passe-o à função--
	
	int n;
	cout << "Insira um número: ";
	cin >> n;
	mostrarNumero(n);
}