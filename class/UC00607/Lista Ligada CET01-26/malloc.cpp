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
int contar() {
	No* ACTUAL = PRIMEIRO;
	int contador = 0;

	while (ACTUAL != NULL) {
		contador++;
		ACTUAL = (*ACTUAL).proximo;
	}
	return contador;
}

// 1 - listar nodes
void listar() {
	cout << endl;
	No* ACTUAL = PRIMEIRO;
	while (ACTUAL != NULL) {
		cout << "\t" << (*ACTUAL).numero << " " << (*ACTUAL).nome << endl;
		ACTUAL = (*ACTUAL).proximo;
	}
}

// b - Inicialização da lista com 3 nodes
void initLista() {
	PRIMEIRO = new No{ 10, "Ana", NULL };
	SEGUNDO = new No{ 20, "Bruno", NULL };
	TERCEIRO = new No{ 30, "Carla", NULL };
	(*PRIMEIRO).proximo = SEGUNDO;
	(*SEGUNDO).proximo = TERCEIRO;
	cout << "\n\tInicializado." << endl;
	listar();
}

// 2 - Inserir novo no início
void inserirInicio(int n, string nome) {
	No* NOVO = new No{ n, nome, NULL };

	// se novo for menor que o primeiro, insere.
	if ((*NOVO).numero < (*PRIMEIRO).numero) {
		No* ACTUAL = PRIMEIRO;
		PRIMEIRO = NOVO;
		(*PRIMEIRO).proximo = ACTUAL;
		cout << "\n\tBloco inserido no inicio." << endl;
	} else cout << "\n\tBloco NAO inserido no inicio." << endl;
}

// 3 - Inserir novo no fim
void inserirFim(int n, string nome) {
	No* NOVO = new No{ n, nome, NULL };
	No* ACTUAL = PRIMEIRO;

	// vai iterando até ao ultimo.
	while (((*ACTUAL).proximo != NULL)) ACTUAL = (*ACTUAL).proximo;

	// se novo for maior que o ultimo, insere novo.
	if ((*NOVO).numero > (*ACTUAL).numero) {
		(*ACTUAL).proximo = NOVO;
		cout << "\n\tBloco inserido no fim." << endl;
	} else cout << "\n\tBloco NAO inserido no fim." << endl;
}

// 4 - Inserir novo ao meio sem deixar inserir na cabeça e na cauda.
void inserirMeio(int n, string nome) {
	No* NOVO = new No{ n, nome, NULL };
	No* ACTUAL = PRIMEIRO;

	// enquanto o novo for maior que o próximo, vai iterando, depois pára.
	while (((*ACTUAL).proximo != NULL) && ((*NOVO).numero > (*(*ACTUAL).proximo).numero)) ACTUAL = (*ACTUAL).proximo;

	// se o actual não for o último e o novo for maior que o actual, insere novo.
	if (((*ACTUAL).proximo != NULL) && ((*NOVO).numero > (*ACTUAL).numero)) {
		(*NOVO).proximo = (*ACTUAL).proximo;
		(*ACTUAL).proximo = NOVO;
		cout << "\n\tBloco inserido ao meio." << endl;
	} else cout << "\n\tBloco NAO inserido ao meio." << endl;
}

// 5 - Inserir novo
void inserir(int n, string nome) {
	inserirInicio(n, nome);
	inserirMeio(n, nome);
	inserirFim(n, nome);
}

// 6 - remove cabeça 
void removerInicio(int n) {
	if (n == (*PRIMEIRO).numero) {
		No* ACTUAL = PRIMEIRO;
		PRIMEIRO = (*PRIMEIRO).proximo;
		delete ACTUAL;
		cout << "\n\tBloco removido no inicio" << endl;
	} else cout << "\n\tBloco NAO removido no inicio" << endl;
}

// 7 - remove fim
void removerFim(int n) {
	No* ACTUAL = PRIMEIRO;

	// vai iterando até ao penultimo.
	while (((*(*ACTUAL).proximo).proximo != NULL)) ACTUAL = (*ACTUAL).proximo;

	if (n == (*(*ACTUAL).proximo).numero) {
		delete (*ACTUAL).proximo;
		(*ACTUAL).proximo = NULL;
		cout << "\n\tBloco removido no fim" << endl;
	} else cout << "\n\tBloco NAO removido no fim" << endl;
}

// 8 - remove ao meio, sem deixar remover no inicio ou no fim.
void removerMeio(int n) {
	No* ACTUAL = PRIMEIRO;

	// enquanto o n for maior do próximo, vai iterando, depois pára.
	while (((*ACTUAL).proximo != NULL) && (n > (*(*ACTUAL).proximo).numero)) ACTUAL = (*ACTUAL).proximo;

	if (((*(*ACTUAL).proximo).proximo != NULL) && (n == (*(*ACTUAL).proximo).numero)) {
		No* SEGUINTE = (*(*ACTUAL).proximo).proximo;
		delete (*ACTUAL).proximo;
		(*ACTUAL).proximo = SEGUINTE;
		cout << "\n\tBloco removido ao meio" << endl;
	} else cout << "\n\tBloco NAO removido ao meio" << endl;
}

void remover(int n) {
	removerInicio(n);
	if (contar() > 2) removerMeio(n);
	if (contar() > 1) removerFim(n);
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
	cout << "\n\tPuff!!!." << endl;
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

// k - sizeof da struct
void calcMem() {
	No* ACTUAL = PRIMEIRO;
	int totalMem=0;
	while (ACTUAL != NULL) {
		totalMem += sizeof(No);
		ACTUAL = (*ACTUAL).proximo;
	}
	cout << "\n\tTamanho em memoria: " << totalMem << " bytes." << endl;
}

int main() {
	int n = 0;
	string nome = "Fulano";
	initLista(); // inicializa a lista para poupar tempo a testar--

	// cenas:
	char op; 
	do {				// MENU DO DIA
		cout << "\nLISTA LIGADA\n[1:listar]\n[a:limpa lista][b:init lista com 3 nos]\n[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]\n[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]\n[c:lista ordenada ? (sim / nao)][d:ordena lista][e:conta nos]\n[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor] [k:sizeof da struct]\n[Y:apaga ate primeiro par] [y:elimina repetido...se...]\n[0:SAIR]\nOp? ";
		cin >> op;
		switch (op) {
			case 'Y':	// apaga até primeiro par
			case'y':
				break;
			case '1':	// listar	
				listar();
				break;
			case '2':	// insere primeiro
				n = pedirNumero(n);
				nome = pedirNome(nome);
				inserirInicio(n, nome);
				listar();
				break;
			case '3':	// insere no fim
				n = pedirNumero(n);
				nome = pedirNome(nome);
				inserirFim(n, nome);
				listar();
				break;
			case '4': {	// insere ao meio
				n = pedirNumero(n);
				nome = pedirNome(nome);
				inserirMeio(n, nome);
				listar();
				break;
			}
			case '5' :	// INSERE(completo)
				n = pedirNumero(n);
				nome = pedirNome(nome);
				inserir(n, nome);
				listar();
				break;
			case '6':	// remove cabeca
				n = pedirNumero(n);
				removerInicio(n);
				listar();
				break;
			case '7':	// remove cauda
				n = pedirNumero(n);
				removerFim(n);
				listar();
				break;
			case '8':	// remove ao meio
				n = pedirNumero(n);
				removerMeio(n);
				listar();
				break;
			case '9':	// REMOVE (completo)
				n = pedirNumero(n);
				remover(n);
				listar();
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
				cout << "\n\tIs this the real life? Is this just fantasy?\n\tCaught in a landslide, no escape from reality\n\tOpen your eyes, look up to the skies and see\n\tI'm just a poor boy, I need no sympathy\n\tBecause I'm easy come, easy go, little high, little low\n\tAny way the wind blows\n\tDoesn't really matter to me, to me\n\n\tMama, just killed a man\n\tPut a gun against his head, pulled my trigger, now he's dead\n\tMama, life had just begun\n\tBut now I've gone and thrown it all away\n\tMama, ooh, didn't mean to make you cry\n\tIf I'm not back again this time tomorrow\n\tCarry on, carry on as if nothing really matters\n\n\tToo late, my time has come\n\tSends shivers down my spine, body's aching all the time\n\tGoodbye, everybody, I've got to go\n\tGotta leave you all behind and face the truth\n\tMama, ooh (Any way the wind blows)\n\tI don't wanna die\n\tI sometimes wish I'd never been born at all\n\n\tI see a little silhouetto of a man\n\tScaramouche, Scaramouche, will you do the Fandango?\n\tThunderbolt and lightning, very, very frightening me\n\t(Galileo) Galileo, (Galileo) Galileo, Galileo Figaro\n\tMagnifico (Oh-oh-oh-oh)\n\tBut I'm just a poor boy, nobody loves me\n\tHe's just a poor boy from a poor family\n\tSpare him his life from this monstrosity\n\tEasy come, easy go, will you let me go?\n\tBismillah, no, we will not let you go (Let him go)\n\tBismillah, we will not let you go (Let him go)\n\tBismillah, we will not let you go (Let me go)\n\tWill not let you go (Let me go)\n\t(Never, never, never, never, never, never let me go) Will not let you go\n\tNo, no, no, no, no, no, no\n\tOh, mamma mia, mamma mia (Mamma mia, let me go)\n\tBeelzebub has a devil put aside for me, for me, for me\n\n\tSo you think you can stone me and spit in my eye?\n\tSo you think you can love me and leave me to die?\n\tOh, baby, can't do this to me, baby\n\tJust gotta get out, just gotta get right outta here\n\n\t(Ooh, yeah, ooh, yeah)\n\tNothing really matters, anyone can see\n\tNothing really matters\n\tNothing really matters to me\n\tAny way the wind blows" << endl;
				break;
			case 'K':
			case 'k':	// sizeof da struct
				calcMem();
				break;
			default:
				break;
		}	
	} while (op != '0');
}