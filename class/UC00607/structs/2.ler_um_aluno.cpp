#include <iostream>
using namespace std;

// Declare uma struct Aluno com nome e idade. Leia os dois campos e apresente-os

struct Aluno {
	string nome;
	double idade;
};

int main() {
	Aluno alunos;
	cout << "Inserir nome e idade: ";
	cin >> alunos.nome >> alunos.idade;
	cout << alunos.nome << " " << alunos.idade;
}