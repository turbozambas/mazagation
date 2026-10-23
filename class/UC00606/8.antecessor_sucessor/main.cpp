#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m8. Antecessor e sucessor\033[0m\n\n";

	int n;

	cout << "Insira um número: ";
	cin >> n;

	cout << "Antecessor: " << n-1 << "\n";
	cout << "Sucessor: " << n+1 << "\n";
}