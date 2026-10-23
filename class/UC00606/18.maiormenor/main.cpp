#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m18. Maior e menor número\033[0m\n\n";

	int quantidade, n, maior, menor;

	cout << "Quantos números pretende introduzir? ";
	cin >> quantidade;

	if (quantidade>0) {
		for (int i=1;i<=quantidade;i++) {
			cout << "Insira um número: ";
			cin >> n;

			if (i==1) {
				maior=n;
				menor=n;
			} else {
				if (n>maior) { maior=n; }
				if (n<menor) { menor=n; }
			}
		}
	}

	cout << "Maior: " << maior << "\n";
	cout << "Menor: " << menor << "\n";
}