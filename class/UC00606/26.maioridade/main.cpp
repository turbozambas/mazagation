#include <iostream>
#include <string>
using namespace std;



bool maiorDeIdade(int idade) {
	if (idade>=18) {
		return true;
	}
	return false;
}

int main() {
	cout << "\033[1m26. Verificar a maioridade\033[0m\n\n";
	// Crie uma função bool maiorDeIdade(int idade) que devolva true quando a idade for igual ou superior a 18 e false nos restantes casos.
	// No main(), leia a idade e apresente uma mensagem adequada--

	int idd;
	cout << "Insira a sua idade: ";
	cin >> idd;

	if (maiorDeIdade(idd)) {
		cout << "Maior de idade\n";
	} else {
		cout << "Menor de idade\n";
	}
}