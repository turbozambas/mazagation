#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	cout << "\033[1m19. Verificação de números primos\033[0m\n\n";
	// Leia um número inteiro positivo e determine se é primo--

	int n;
	bool primo = true; // assume por defeito que todos os números são primos

	cout << "Insira um número: ";
	cin >> n;

	if (n>=2) {
		for (int i=2; i<=sqrt(n+1); i++) { // raiz de n não funciona visto que a raiz de 3 é menor que 2 e o ciclo avaria, daí o sqrt(n+1)-- A dica do PJ faz todo sentido!
			if (n%i==0) { // basta encontrar um resto zero para concluir que o número não é primo
				primo = false;
				break;
			}
		}
	} else { // qualquer número inferior a 2 não é primo
		primo = false;
	}

	if (primo) {
		cout << n << " é número primo.\n";
	} else {
		cout << n << " não é número primo.\n";
	}
}