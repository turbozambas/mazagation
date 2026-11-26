#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//tipificação de struct para lista ligada
struct No { int numero; string nome; struct No* proximo; };

No* PRIMEIRO = NULL;
No* SEGUNDO = NULL;
No* TERCEIRO = NULL;

/*void inserirMeio() {
	No* NOVO = new No{15, "Bernardo", NULL };
	No* ACTUAL = PRIMEIRO;
	No* ANTERIOR = PRIMEIRO;
	
	while (ACTUAL != NULL) {
		if ((*NOVO).numero < (*ACTUAL).numero) {
			(*NOVO).proximo = (*ACTUAL).proximo;
			(*ANTERIOR).proximo = (*ACTUAL).proximo;
		} else cout << "erro...";
		ANTERIOR = ACTUAL;
		ACTUAL = (*ACTUAL).proximo;
	}
} */


void inserirMeio() {
	No* NOVO = new No{ 15, "Bernardo", NULL };
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		cout << NOVO << endl;

		if ((*NOVO).numero < (*(*ACTUAL).proximo).numero && (*NOVO).numero >(*ACTUAL).numero) {
			
			(*NOVO).proximo = (*ACTUAL).proximo;
			(*ACTUAL).proximo = NOVO;
		}
		ACTUAL = (*ACTUAL).proximo;
	}
}

void contar() {
	No* ACTUAL = PRIMEIRO;
	int contador = 0;

	while (ACTUAL != NULL) {
		contador++;
		ACTUAL = (*ACTUAL).proximo;
	}
	cout << contador << " nós." << endl;
}

void initLista() {
	// INIT LISTA COM 3 NODES
	PRIMEIRO = new No{ 10, "Ana", NULL };
	SEGUNDO = new No{ 20, "Bruno", NULL };
	TERCEIRO = new No{ 30, "Carla", NULL };

	(*PRIMEIRO).proximo = SEGUNDO;
	(*SEGUNDO).proximo = TERCEIRO;
	cout << "inicializado";
}

void listar() {
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		cout << (*ACTUAL).numero << " - " << (*ACTUAL).nome << endl;
		ACTUAL = (*ACTUAL).proximo;
	}
	cout << "listado";
}

void apagarLista() {
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		No* PROXIMO = (*ACTUAL).proximo;
		delete ACTUAL;
		ACTUAL = PROXIMO;
	}
	PRIMEIRO = NULL;
}

int main()
{
	initLista();
	//dados genéricos para o programa:
	char op; 
	int contador;
	do
	{
		cout << "\n\nLISTA LIGADA-EXERCICIO DIDATICO (TRABALHO COOPERATIVO) \n";
		cout << "[1:listar]\n"
			 <<	"[a:limpa lista][b:init lista com 3 nos]\n"
			 << "[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]" << "\n"
			 << "[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]\n"
			 << "[c:lista ordenada ? (sim / nao)][d:ordena lista][e:conta nos]\n"
			 << "[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor] [k:sizeof da struct] \n"
			 << "[Y:apaga ate primeiro par] [y:elimina repetido...se...]"
			 << "\n[0:SAIR]\n"
			<< "Op?"; 
		cin >> op;//MENU
		switch (op)
		{
		case 'Y':			
			break;
		case'y':
			break;
		case '1':		
			listar();
			break;
		case '2':
			break;
		case '3':		
			break;
		case '4':
			inserirMeio();
			break;
		case '5' :
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
			break;
		case 'A':
		case 'a':
			apagarLista();
			break;
		case 'B':
		case 'b':
			initLista();
			break;
		case 'C':
		case 'c':
			break;
		case 'D':
		case 'd':
			break;
		case 'E':
		case 'e':
			contar();
			break;
		case 'F':
		case 'f':
			break;
		case 'G':
		case 'g':
			break;
		case 'H':
		case 'h':
			cout << "fazer algoritmos!...";
			break;
		case 'K':
		case 'k':
			break;
		default:
			cout << "\7"; //beep do sistema
			break;
		}	
	} while (op != '0');
}