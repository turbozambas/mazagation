#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m6. Dobro de um número\033[0m\n\n";

	int n;

	cout << "Insira um número: ";
	cin >> n;

	cout << "O dobro é: " << n*2 << "\n";
}