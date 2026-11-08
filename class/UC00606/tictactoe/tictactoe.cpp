#include <string>
#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // board setup
char tags[2]={'O','X'};
int t=1, o; // turn counter and selected option
bool p,w=false; // player

void printBoard() {
    cout << "\n";
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (j==2) cout << board[i][j] << "\n";
            else cout << board[i][j];
        }
    }
}

void setPlayer() {
    if (t%2==0) p=0; // turn controls who goes next
    else p=1;
    cout << "\nTurn " << t << ": It's \033[1m" << tags[p] << "\033[0m's turn";
}

void updateBoard(int y, int x) {
    board[y][x]=tags[p];
    t++;
}

void move() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            char pos = board[i][j]; // gets char from board position
            if ((pos!='X' && pos-'0'==o) || (pos!='O' && pos-'0'==o)) updateBoard(i,j);
        }
    }
}

void askPlayerMove() {
    // player's move
    cout << "Your move?... ";
    cin >> o;
    if (o>0 && o<10) move();
    else cout << "\nnabo!\n";
}

void victory() {
    cout << "\n";
    printBoard();
    cout << "\n\033[1m*** " << tags[p] << " wins! Congratulations, bye bye! ***\033[0m\n";
    w=true;
}

void checkRows() {
    for (int i=0;i<3;i++) {
        if ((board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X') || (board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')) victory();
    }
}

void checkColumns() {
    for (int i=0;i<3;i++) {
        if ((board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X') || (board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')) victory();
    }
}

void checkDiagonals() {
    if ((board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')) victory();
    else if ((board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X') || (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')) victory();
}

void checkWinConditions() {
        checkRows();
        checkColumns();
        checkDiagonals();
}

int main() {
    cout << "\033[1m*** tic tac toe ***\033[0m\n"; // hello!
    do { // main game cycle
        setPlayer();
        printBoard();
        askPlayerMove();
        checkWinConditions();
    } while (t<10 && !w); // only 9 turns to play!
    if (!w) printBoard();
    return 0;
}