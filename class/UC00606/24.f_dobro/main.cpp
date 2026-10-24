#include <iostream>
#include <string>
using namespace std;

int dobro(int numero) {
	return numero*2;
}

int main() {
	cout << "\033[1m24. Calcular o dobro\033[0m\n\n";
	// Crie uma função int dobro(int numero) que devolva o dobro do valor recibido.
	// No main(), leia um número e apresente o resultado devolvido--
	
	int n;
	cout << "Insira um número: ";
	cin >> n;

	cout << dobro(n) << "\n";
}