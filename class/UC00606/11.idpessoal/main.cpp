#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m11. Identificação pessoal\033[0m\n\n";
	// Leia o nome, a idade e a localidade de uma pessoa. Apresente uma frase com os três dados indroduzidos--

	string nome, local;
	int idade;

	cout << "Nome: ";
	cin >> nome;
	cout << "Idade: ";
	cin >> idade;
	cout << "Localidade: ";
	cin >> local;

	cout << nome << " tem " << idade << " anos e vive em " << local << ".\n";
}