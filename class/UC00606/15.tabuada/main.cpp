#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m15. Tabuada de um número\033[0m\n\n";
	// Leia um número inteiro entre 1 e 10 e apresente a respetiva tabuada, de 1 a 10, utilizando um ciclo for.
	// Se o número estiver fora do intervalo, apresente uma mensagem de erro--

	int n;

	cout << "Insira um número de 1 a 10: ";
	cin >> n;

	if (n>=1 && n<=10) {
		for (int i=1;i<=10;i++) {
			cout << n << "x" << i << "=" << n * i << "\n";
		}
	} else cout << "Por favor, insira um número decente!\n";
}