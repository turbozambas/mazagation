#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
using namespace std;

// player related declarations
#define PLAYER_1 "\033[38;2;217;164;65m"
#define PLAYER_2 "\033[38;2;75;165;225m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
string COLOR;
bool player;
int startPosition=0,endPosition=15,p;
int beads[2][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
char tags[2]={'B','Y'};

// board related declarations
char board[3][8];
int paths[2][16][2]={
    {{2,4},{2,3},{2,2},{2,1},{2,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,7},{2,6},{2,5}},  // player1
    {{0,4},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}}   // player2
};
int rosettes[5][2]={{0,0},{2,0},{1,3},{0,6},{2,6}};
int rosettesPositions[3]={4,8,14};

// game mechanics related declarations
int turn=1, opt=0;
bool win=false;

// RNG (cppreference.com/cpp/numeric/random/uniform_int_distribution)
int randomNumber(int x, int y) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(x, y);
    return dist(gen);
}

int checkBeads(int p) {
    int c=0; // elderlywomanbehindacounterinasmalltown
    for (int i=0;i<7;i++) if (beads[player][i]<15) c++;
    return c;
}

void printBoard() {
    //system("clear");
    for (int i=0;i<5;i++) {
        if (board[rosettes[i][0]][rosettes[i][1]]=='B' || board[rosettes[i][0]][rosettes[i][1]]=='Y') cout << "";
        else board[rosettes[i][0]][rosettes[i][1]]='*';
    }
    
    for (int i=0;i<3;i++) {
        for (int j=0;j<8;j++) {
            if (board[i][j]=='B' || board[i][j]=='Y') cout << "";
            else if (board[i][j]=='*') board[i][j]='*';
            else if ((j>=4 && j<=5 && i==0) || (j>=4 && j<=5 && i==2)) board[i][j]=' ';
            else board[i][j]='-';
            cout << board[i][j];
        }
        cout << endl;
    }
}

void setPlayer() {
    if (turn%2==0) { // let turn decide who plays next
        player=0;
        p=2; // just so it shows "Player 2" instead of "Player 0"
        COLOR=PLAYER_2;
    }
    else {
        player=1;
        p=1;
        COLOR=PLAYER_1;
    }
}

bool checkCellIsFree(int p, int y) {
    if (board[paths[player][y][0]][paths[player][y][1]]=='-' || board[paths[player][y][0]][paths[player][y][1]]=='*' || board[paths[player][y][0]][paths[player][y][1]]==tags[player]) return true;
    //cout << board[paths[player][y][0]][paths[player][y][1]];
    return false;
}

void listBeads() {
    cout << "|";
    for (int i=0;i<7;i++) cout << beads[player][i] << "|";
    cout << endl;
}

int move(int r, int o) {
    if (checkCellIsFree(player, beads[player][o]+r)) {
        board[paths[player][beads[player][o]][0]][paths[player][beads[player][o]][1]]='-';
        beads[player][o]+=r;
        board[paths[player][beads[player][o]][0]][paths[player][beads[player][o]][1]]=tags[player];
        listBeads();
        turn++;
        return o;
    }
}

void askPlayerMove(int r) {
    int n=checkBeads(player);
    cout << "Your move?... ";
    cin >> opt;
    cout << beads[player][opt]+r << endl;
    if (opt>=0 && opt<=7 && beads[player][opt]+r<16 && checkCellIsFree(player, beads[player][opt]+r)) move(r, opt);
}

void rollDice() {
    int r=randomNumber(0,4);
    cout << COLOR << BOLD << " * Turn " << turn << " Player " << p << " rolls " << r << RESET << endl;
    listBeads();
    if (r>0) askPlayerMove(r);
    if (r==0) turn++;
}

void checkWinConditions() {
    for (int i=0;i<2;i++) {
        int c=0; // elderlywomanbehindacounterinasmalltown
        for (int j=0;j<7;j++) {
            if (beads[i][j]==endPosition) c++;
        }
        if (c==7) {
            cout << "we have a winner!" << endl;
            win=true;
        }
    }
}

int main() {
    cout << BOLD << "*** Royal Game of Ur ***" << RESET << endl; // hello!
    do {
        printBoard();
        setPlayer();
        rollDice();
        checkWinConditions();
    } while (!win);
}