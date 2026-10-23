#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m16. Contagem de números pares e ímpares\033[0m\n\n";

	int n, pares=0, i=1, cont=10;

	do {
		cout << "Insira um número: ";
		cin >> n;
		if (n%2==0) pares++;
		i++;
	} while (i<=cont);

	cout << pares << " números pares, e " << cont-pares << " impares.\n";
}