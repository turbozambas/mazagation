#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m9. Positivo, negativo ou zero\033[0m\n\n";

	int n;

	cout << "Insira um número: ";
	cin >> n;

	if (n<0) { cout << "O número é negativo\n"; }
	if (n>0) { cout << "O número é positivo\n"; }
	if (n==0) { cout << "O número é zero\n"; }
}