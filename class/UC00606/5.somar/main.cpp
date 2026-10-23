#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m5. Somar dois números\033[0m\n\n";

	int n1, n2;

	cout << "Insira um número: ";
	cin >> n1;
	cout << "Insira outro número: ";
	cin >> n2;

	cout << "A soma é: " << n1+n2 << "\n";
}