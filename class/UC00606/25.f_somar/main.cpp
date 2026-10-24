#include <iostream>
#include <string>
using namespace std;

int somar(int a, int b) {
	return a+b;
}

int main() {
	cout << "\033[1m25. Somar dois inteiros\033[0m\n\n";
	// Crie uma função int somar(int a, int b) que devolva a soma de dois inteiros. No main(), leia dois números, chame a função e apresente o resultado--
	
	int n1, n2;
	cout << "Insira um número: ";
	cin >> n1;
	cout << "Insira outro número: ";
	cin >> n2;
	
	cout << somar(n1,n2) << "\n";
}