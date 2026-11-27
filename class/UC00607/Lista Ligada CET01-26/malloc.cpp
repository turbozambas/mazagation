#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// tipificação de struct para lista ligada
struct No { int numero; string nome; struct No* proximo; };
No* PRIMEIRO = NULL;
No* SEGUNDO = NULL;
No* TERCEIRO = NULL;

// e - contar nodes
void contar() {
	No* ACTUAL = PRIMEIRO;
	int contador = 0;

	while (ACTUAL != NULL) {
		contador++;
		ACTUAL = (*ACTUAL).proximo;
	}
	cout << contador << " nós." << endl;
}

// 1 - listar nodes
void listar() {
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		cout << (*ACTUAL).numero << " " << (*ACTUAL).nome << endl;
		ACTUAL = (*ACTUAL).proximo;
	}
}

// b - init lista com 3 nos
void initLista() {
	PRIMEIRO = new No{ 10, "Ana", NULL };
	SEGUNDO = new No{ 20, "Bruno", NULL };
	TERCEIRO = new No{ 30, "Carla", NULL };
	(*PRIMEIRO).proximo = SEGUNDO;
	(*SEGUNDO).proximo = TERCEIRO;
	cout << "\nInicializado." << endl;
	listar();
}

// 3 - Inserir ao meio sem deixar inserir na cabeça e na cauda.
void inserirMeio(int n, string nome) {
	No* NOVO = new No{ n, nome, NULL };
	No* ACTUAL = PRIMEIRO;

	// enquanto o novo for maior que o próximo, vai iterando, depois pára.
	while (((*ACTUAL).proximo != NULL) && ((*NOVO).numero > (*(*ACTUAL).proximo).numero)) ACTUAL = (*ACTUAL).proximo;

	// se o actual não for o último e o novo maior que o actual, insere e lista.
	if (((*ACTUAL).proximo != NULL) && ((*NOVO).numero > (*ACTUAL).numero)) {
		(*NOVO).proximo = (*ACTUAL).proximo;
		(*ACTUAL).proximo = NOVO;
		cout << "\nBloco inserido." << endl;
	} else cout << "\nBloco NAO inserido. Adeus!" << endl;
	listar();
}

// a - limpar lista
void apagarLista() {
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		No* PROXIMO = (*ACTUAL).proximo;
		delete ACTUAL;
		ACTUAL = PROXIMO;
	}
	PRIMEIRO = NULL;
	cout << "\nPuff!!!." << endl;
	listar();
}

// função simples para pedir um nome
string pedirNome(string nome) {
	cout << "Insira um nome: ";
	cin >> nome;
	return nome;
}

// função simples para pedir um número
int pedirNumero(int numero) {
	cout << "Insira um inteiro: ";
	cin >> numero;
	return numero;
}

int main() {
	initLista(); // inicializa a lista para poupar tempo a testar--

	// cenas:
	char op; 
	do {				// MENU DO DIA
		cout << "\nLISTA LIGADA" << endl;
		cout << "[1:listar]" << endl
			<< "[a:limpa lista][b:init lista com 3 nos]" << endl
			<< "[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]" << endl
			<< "[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]" << endl
			<< "[c:lista ordenada ? (sim / nao)][d:ordena lista][e:conta nos]" << endl
			<< "[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor] [k:sizeof da struct]" << endl
			<< "[Y:apaga ate primeiro par] [y:elimina repetido...se...]" << endl
			<< "[0:SAIR]" << endl
			<< "Op?";
		cin >> op;
		switch (op) {
			case 'Y':	// apaga até primeiro par
			case'y':
				break;
			case '1':	// listar	
				listar();
				break;
			case '2':	// insere primeiro
				break;
			case '3':	// insere no fim
				break;
			case '4': {	// insere ao meio
						int n = 0;
						string nome = "Fulano";
						n = pedirNumero(n);
						nome = pedirNome(nome);
						inserirMeio(n, nome);
						break;
					}
			case '5' :	// INSERE(completo)
				break;
			case '6':	// remove cabeca
				break;
			case '7':	// remove cauda
				break;
			case '8':	// remove ao meio
				break;
			case '9':	// REMOVE (completo)
				break;
			case 'A':
			case 'a':	// limpar lista
				apagarLista();
				break;
			case 'B':
			case 'b':	// init lista com 3 nodes
				initLista();
				break;
			case 'C':
			case 'c':	// lista ordenada? (y/n)
				break;
			case 'D':
			case 'd':	// ordena lista
				break;
			case 'E':
			case 'e':	// conta nodes
				contar();
				break;
			case 'F':
			case 'f':	// ler dois números
				break;
			case 'G':
			case 'g':	// inverter a lista
				break;
			case 'H':
			case 'h':	// lulz!
				cout << "fazer algoritmos, nabo!..." << endl;
				break;
			case 'K':
			case 'k':	// sizeof da struct
				break;
			default:
				break;
		}	
	} while (op != '0');
}