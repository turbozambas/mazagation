#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m4. Ler e mostrar a idade\033[0m\n\n";

	int idade;

	cout << "Insira a sua idade: ";
	cin >> idade;

	cout << "A sua idade é: " << idade << "\n";
}