#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m19. Verificação de números primos\033[0m\n\n";

	int n;
	bool primo = true;

	cout << "Insira um número: ";
	cin >> n;

	if (n>2) {
		for (int i=2; i<n; i++) {
			if (n%i==0) {
				primo = false;
				break;
			}
		}
	} else {
		primo = false;
	}

	if (primo == true) {
		cout << n << " é número primo.\n";
	} else {
		cout << n << " não é número primo.\n";
	}
}