#include <iostream>
#include <string>
using namespace std;

int maior(int a, int b) {
	int maior = a;
	if (b>maior) maior=b;
	return maior;
}

int main() {
	cout << "\033[1m29. Encontrar o maior de dois números\033[0m\n\n";
	// Crie uma função int maior(int a, int b) que devolva o maior de dois inteiros.
	// No main(), leia dois números e apresente o valor devolvido pela função--

	int n1, n2;

	cout << "Insira um número: ";
	cin >> n1;
	cout << "Insira outro número: ";
	cin >> n2;

	cout << maior(n1,n2) << "\n";
}