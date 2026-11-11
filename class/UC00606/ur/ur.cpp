#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
using namespace std;

int turn=0, rng;
bool win=false, tryAgain=false;
string landing;

// player related declarations
struct Player {
    string tag;
    string color;
    int beads[7], p, paths[16][2];
};
Player players[2];
bool player,opponent;

// board related declarations
string board[3][8];
int paths[2][16][2]={
    {{2,4},{2,3},{2,2},{2,1},{2,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,7},{2,6},{2,5}},
    {{0,4},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}}
};
int rosettes[5][2]={{0,0},{2,0},{1,3},{0,6},{2,6}};
string reset="\033[0m", bold="\033[1m";

// RNG (cppreference.com/cpp/numeric/random/uniform_int_distribution)
int randomNumber(int x, int y) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(x, y);
    return dist(gen);
}
void init() {
    cout << bold << "\n\n\t*** Royal Game of Ur ***" << reset << endl; // hello!
    // player related initialization
    players[0].tag='Y';
    players[1].tag='B';
    players[0].color="\033[38;2;217;164;65m";
    players[1].color="\033[38;2;75;165;225m";
    for (int i=0;i<7;i++) {
        players[0].beads[i]=0;
        players[1].beads[i]=0;
    } 
    for (int i=0;i<16;i++) {
        for (int j=0;j<2;j++) {
            players[0].paths[i][j]=paths[0][i][j];
            players[1].paths[i][j]=paths[1][i][j];
        }
    }   
    players[0].p=1;
    players[1].p=2;
}

int checkBeads(int y, int z) {
    int c=0; // elderlywomanbehindacounterinasmalltown
    for (int i=0;i<7;i++) if (players[y].beads[i]==z) c++;
    return c;
}

void printBoard() {
    for (int i=0;i<3;i++) for (int j=0;j<8;j++) board[i][j]="  ";
    for (int i=0;i<5;i++) board[rosettes[i][0]][rosettes[i][1]]="**";
    for (int i=0;i<2;i++) for (int j=0;j<7;j++) board[paths[i][players[i].beads[j]][0]][paths[i][players[i].beads[j]][1]]=bold+players[i].color+players[i].tag + to_string(j)+reset;
    cout << endl;
    // print board
    string canvas[7][17] = {
        {"\t##","##","##","##","##","##","##","##","##",board[0][4],"  ",board[0][5],"##","##","##","##","##"},
        {"\t##",board[0][0],"##",board[0][1],"##",board[0][2],"##",board[0][3],"##","  ","  ","  ","##",board[0][6],"##",board[0][7],"##"},
        {"\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"},
        {"\t##",board[1][0],"##",board[1][1],"##",board[1][2],"##",board[1][3],"##",board[1][4],"##",board[1][5],"##",board[1][6],"##",board[1][7],"##"},
        {"\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"},
        {"\t##",board[2][0],"##",board[2][1],"##",board[2][2],"##",board[2][3],"##","  ","  ","  ","##",board[2][6],"##",board[2][7],"##"},
        {"\t##","##","##","##","##","##","##","##","##",board[2][4],"  ",board[2][5],"##","##","##","##","##"}
    };
    for (int i=0;i<7;i++) {
        for (int j=0;j<17;j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
    for (int i=0;i<2;i++) {
        cout << players[i].color << bold << "\n\tPlayer " << players[i].p << ": ";
        for (int j=0;j<16;j++) {
            string b[2]={">(",")>"};
            if (j==0 || j==15) {
                b[0]=players[i].color+bold+" [ ";
                b[1]=" ] "+reset;
                cout << b[0] << checkBeads(i,j) << b[1];
            } else cout << b[0] << board[players[i].paths[j][0]][players[i].paths[j][1]] << b[1];
        }
        cout << "\n";
    }
}

void errorMsg() {
    cout << bold << "\n\tThese aren't the droids you're looking for. Move along!\n" << reset;
}

void setPlayer() { // turn decides who plays next
    if (turn%2==0) {
        player=0;
        opponent=1;
    }
    else {
        player=1;
        opponent=0;
    }
}

bool checkCellIsFree(int pos) {
    for (int i=0;i<7;i++) if (players[player].beads[i]==pos || (players[opponent].beads[i]==pos && pos==8)) return false;
    return true;
}

void checkCellIsOpponent(int pos) {
    for (int i=0;i<7;i++) if (players[opponent].beads[i]==pos && pos>=5 && pos<=12 && pos!=8) players[opponent].beads[i]=0;
}

int move(int o, int pos) {
    board[players[player].paths[o][0]][players[player].paths[o][1]]="  "; // clears previous position
    players[player].beads[o]+=rng; // move bead to new position
    landing=board[players[player].paths[pos][0]][players[player].paths[pos][1]]; // records landing position
    board[players[player].paths[o][0]][players[player].paths[o][1]]=players[player].tag;
    tryAgain=false;
    checkCellIsOpponent(pos);
    if (landing=="**") return 0;
    else turn++;
    return 0;
}

void askPlayerMove() {
    int opt;
    cout << "\n\tYour move?... ";
    cin >> opt;
    if (opt>=0 && opt<7 && players[player].beads[opt]+rng<16 && checkCellIsFree(players[player].beads[opt]+rng)) move(opt, players[player].beads[opt]+rng);
    else {
        errorMsg();
        tryAgain=true;
    }
}

void rollDice() {
    rng=randomNumber(0,4);
    cout << players[player].color << bold << "\n\tPlayer " << players[player].p << " rolls " << rng << reset << endl;
    if (rng>0) askPlayerMove();
    if (rng==0) turn++;
}

void checkWinConditions() {
    for (int i=0;i<2;i++) {
        int c=0; // elderlywomanbehindacounterinasmalltown
        for (int j=0;j<7;j++) {
            if (players[i].beads[j]==15) c++;
        }
        if (c==7) {
            cout << bold << "\n\tGAME OVER\n" << endl;
            win=true;
        }
    }
}

int main() {
    init();
    do {
        setPlayer();
        printBoard();
        if (tryAgain) askPlayerMove();
        else rollDice();
        checkWinConditions();
    } while (!win);
    return 0;
}