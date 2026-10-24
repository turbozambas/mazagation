#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m9. Positivo, negativo ou zero\033[0m\n\n";
	// Leia um número inteiro e indique se é positivo, negativo ou igual a zero, utilizando if e else--

	int n;

	cout << "Insira um número: ";
	cin >> n;

	if (n<0) { cout << "O número é negativo\n"; }
	else if (n>0) { cout << "O número é positivo\n"; }
	else { cout << "O número é zero\n"; }
}