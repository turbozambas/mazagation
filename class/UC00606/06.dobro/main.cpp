#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m6. Dobro de um número\033[0m\n\n";
	// Leia um número inteiro e apresente o seu dobro--

	int n;

	cout << "Insira um número: ";
	cin >> n;

	cout << "O dobro é: " << n*2 << "\n";
}