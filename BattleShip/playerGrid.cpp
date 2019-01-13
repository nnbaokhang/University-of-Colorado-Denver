//
// Created by khang on 9/29/2018.
//
#include "playerGrid.h"
using namespace std;


int BfireatA(playerGrid& A,std::string a[10][10]){
    // Loop in the back
    // Loop through player grid
    // If match then hit if no match then no hit
    int X;
    int Y;
    X = rand() % 10;
    Y = rand() % 10;
    while(A.isAlreadyHit(X,Y,a)) {
        X = rand() % 10;
        Y = rand() % 10;
    }
    // Need to access player grid
    //If at (x,y) exist a part of a ship
    //If true then destroy that ship
    //If false then mark at nothing
    if(A.check(X,Y)) {
        a[X][Y] = "X";
        A.status(X,Y);
        A.shipDestroy(a);
    }
    else {
        a[X][Y] = "0";
      cout << "Computer hit at nothing" << endl;
    }
    if(A.Carrier.length <  5&& A.Cruiser.length < 3 && A.BattleShip.length < 4 && A.Submarine.length < 3
       && A.Destroyer.length <  2) {

        cout << "***Haha. Computer destroyed everyone ship***" << endl;
        return 1;
    }
     if(A.Carrier.length < 5 && A.Carrier.alreadyPlace == 1) {

        cout << "***Awe. Computer have destroy your carrier ship***" << endl;
        A.Carrier.alreadyPlace = 0;
    }
     if (A.Cruiser.length < 3 && A.Cruiser.alreadyPlace == 1) {
        cout << "***Awe. Computer have destroy your cruiser ship***" << endl;
        A.Cruiser.alreadyPlace = 0;
    }
     if (A.BattleShip.length < 4 && A.BattleShip.alreadyPlace == 1){
        cout <<"***Awe. Computer have destroy your battleship***" << endl;
        A.BattleShip.alreadyPlace = 0;
    }
     if(A.Submarine.length < 3 && A.Submarine.alreadyPlace == 1){
        cout <<"***Awe. Computer have destroy your submarine ship***" << endl;
        A.Submarine.alreadyPlace = 0;
    }
     if (A.Destroyer.length < 2 && A.Destroyer.alreadyPlace == 1){
        cout <<"***Awe. Computer have destroy your destroyer ship***" << endl;
        A.Destroyer.alreadyPlace = 0;
    }

    return 0;
}
void playerGrid::getGrid(std::string a[10][10]){
    for(int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            a[i][j] = grid[i][j];
        }
    }
}