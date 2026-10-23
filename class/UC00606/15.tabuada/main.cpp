#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m15. Tabuada de um número\033[0m\n\n";

	int n;

	cout << "Insira um número de 1 a 10: ";
	cin >> n;

	if (n>=1 && n<=10) {
		for (int i=1;i<=10;i++) {
			cout << n << "x" << i << "=" << n * i << "\n";
		}
	} else cout << "Por favor, insira um número decente!\n";
}