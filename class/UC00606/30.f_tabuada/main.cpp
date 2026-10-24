#include <iostream>
#include <string>
using namespace std;

void tabuada(int numero) {
	for (int i=1;i<=10;i++) {
		cout << numero << "x" << i << "=" << numero*i << "\n";
	}
}

int main() {
	cout << "\033[1m30. Mostrar uma tabuada\033[0m\n\n";
	// Crie uma função void tabuada(int numero) que apresente a tabuada do número recebido, de 1 a 10, utilizando um ciclo for.
	// No main(), leia um inteiro entre 1 e 10, valide-o, se for válido, chame a função.

	int n;

	cout << "Insira um numero: ";
	cin >> n;

	if (n>=1 && n<=10) {
		tabuada(n);
	}
}