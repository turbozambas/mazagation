#include <string>
#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // board setup
char tags[2]={'O','X'};
int t=1, o; // turn counter and selected option
bool p=0; // player

void printBoard() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (j==2) cout << board[i][j] << "\n";
            else cout << board[i][j];
        }
    }
}

void setPlayer() {
    if (t%2==0) p=0; // turn controls which player is next
    else p=1;
    cout << "Round " << t << ": It's \033[1m" << tags[p] << "\033[0m's turn...\n";
}

void updateBoard(int x, int y) {
    board[y][x]=tags[p];
    if (t==9) printBoard();
    t++;
}

void move() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            char pos = board[i][j]; // set current position on the board
            if (pos!='X' || pos!='O') {
                if (pos-'0'==o) {
                    updateBoard(j,i);
                }
            }
        }
    }
}

void askPlayerMove() {
    // player's move
    cin >> o;
    if (o>0 && o<10) move();
}

int main() {
    cout << "\033[1m*** tic tac toe ***\033[0m\n"; // hello!
    do { // main game cycle
        setPlayer();
        printBoard();
        askPlayerMove();
    } while (t<10); // only 9 turns to play!
}