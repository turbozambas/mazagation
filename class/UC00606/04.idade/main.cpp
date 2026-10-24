#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m4. Ler e mostrar a idade\033[0m\n\n";
	// Peça ao utilizador a sua idade (número inteiro) e apresente: A sua idade é: ..., substituindo os pontos pelo valor introduzido--

	int idade;
	cout << "Insira a sua idade: ";
	cin >> idade;
	cout << "A sua idade é: " << idade << "\n";
}