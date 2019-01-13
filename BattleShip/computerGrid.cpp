//
// Created by khang on 10/7/2018.
//

#include "computerGrid.h"
#include "playerGrid.h"
using namespace std;


bool computerGrid::setLocation(){
//Set a ship
// Check if space available
// Fill
    symbol = "C";
    int direction;
    int n = 0;
    while(Carrier.alreadyPlace == 0) {
        n++;
        Carrier.Y = rand() % n ;
        Carrier.X = rand() % (n + 1);
        direction = (rand()+n) % 2;
        if (direction == 0)
            Carrier.Z = 'H';
        else
            Carrier.Z = 'V';
        if (checkSpace(Carrier.X, Carrier.Y, Carrier.Z, Carrier.length) && Carrier.alreadyPlace == 0) {
            fillGrid(symbol, Carrier.X, Carrier.Y, Carrier.Z, Carrier.length);
            Carrier.alreadyPlace = 1;
        }
    }
    symbol = "D";
    while(Destroyer.alreadyPlace == 0) {
        n++;
        Destroyer.Y = rand() % n ;
        Destroyer.X = rand() % (n + 1);
        direction = (rand() + n + 1) % 2;
        if (direction == 0)
           Destroyer.Z = 'H';
        else
            Destroyer.Z = 'V';
        if (checkSpace(Destroyer.X, Destroyer.Y, Destroyer.Z, Destroyer.length) && Destroyer.alreadyPlace == 0) {
            fillGrid(symbol, Destroyer.X, Destroyer.Y, Destroyer.Z, Destroyer.length);
            Destroyer.alreadyPlace = 1;
        }
    }
    symbol = "B";
    while(BattleShip.alreadyPlace == 0) {
        n++;
        BattleShip.Y = rand() % n ;
        BattleShip.X = rand() % (n + 1);
        direction = (rand()+n + 2) % 2;
        if (direction == 0)
            BattleShip.Z = 'H';
        else
            BattleShip.Z = 'V';
        if (checkSpace(BattleShip.X, BattleShip.Y, BattleShip.Z, BattleShip.length) && BattleShip.alreadyPlace == 0) {
            fillGrid(symbol, BattleShip.X, BattleShip.Y, BattleShip.Z, BattleShip.length);
            BattleShip.alreadyPlace = 1;
        }
    }
    symbol = "R";
    while(Cruiser.alreadyPlace == 0) {
        n++;
        Cruiser.Y = rand() % n ;
        Cruiser.X = rand() % (n + 1);
        direction = (rand() + n + 3) % 2;
        if (direction == 0)
            Cruiser.Z = 'H';
        else
            Cruiser.Z = 'V';
        if (checkSpace(Cruiser.X, Cruiser.Y, Cruiser.Z, Cruiser.length) && Cruiser.alreadyPlace == 0) {
            fillGrid(symbol, Cruiser.X, Cruiser.Y, Cruiser.Z, Cruiser.length);
            Cruiser.alreadyPlace = 1;
        }
    }
    symbol = "S";

    while(Submarine.alreadyPlace == 0) {
        n++;
        Submarine.Y = rand() % n ;
        Submarine.X = rand() % (n + 1);
        direction = (rand() + n + 4) % 2;
        if (direction == 0)
            Submarine.Z = 'H';
        else
            Submarine.Z = 'V';
        if (checkSpace(Submarine.X, Submarine.Y, Submarine.Z, Submarine.length) && Submarine.alreadyPlace == 0) {
            fillGrid("S", Submarine.X, Submarine.Y, Submarine.Z, Submarine.length);
            Submarine.alreadyPlace = 1;
        }
    }
return 0;
}

int AfireatB(int X,int Y,computerGrid& B, std::string a[10][10]){

    // Loop in the back
    // Loop through computer grid
    // If match then hit if no match then no hit
    while(B.isAlreadyHit(X,Y,a)) {
        cout << "You already hit this position" << endl;
        cout <<"Please try again" << endl;
        char y ,x;
        do {
            //Check if input is valid{
            cout << "Please input x from A to J | y from 0 to 9" << endl;
            cin >> y >> x;
        }while(y < 'A' || y > 'J' || x < '0' || x > '9');
        Y = y -65;
        X = x - 48;
        cin.ignore();
    }
    // Need to access computer grid
    //If at(x,y) exist a part of a ship
    // If true then mark ship destroyed
    // If not then mark nothing
    if(B.check(X,Y)) {
        a[X][Y] = "X";
        B.status(X,Y);
        B.shipDestroy(a);
    }
    else {
        a[X][Y] = "0";
    cout <<"You hit at nothing" << endl;
    }
    if(B.Carrier.length <  5&& B.Cruiser.length < 3 && B.BattleShip.length < 4 && B.Submarine.length < 3
       && B.Destroyer.length <  2) {
        cout << "***Haha. You destroyed everyone ship***" << endl;
        return 1;
    }
     if(B.Carrier.length < 5 && B.Carrier.alreadyPlace == 1) {
        cout << "***Awe. You have destroy computer carrier ship***" << endl;
        B.Carrier.alreadyPlace = 0;
     }
     if (B.Cruiser.length < 3 && B.Cruiser.alreadyPlace == 1) {
        cout << "***Awe. You have destroy computer cruiser ship***" << endl;
       B.Cruiser.alreadyPlace = 0;
    }
     if (B.BattleShip.length < 4 && B.BattleShip.alreadyPlace == 1){
        cout <<"***Awe. You have destroy computer battleship***" << endl;
       B.BattleShip.alreadyPlace = 0;
    }
     if(B.Submarine.length < 3 && B.Submarine.alreadyPlace == 1){
        cout <<"***Awe. You have destroy computer submarine ship***" << endl;
       B.Submarine.alreadyPlace = 0;
    }
     if (B.Destroyer.length < 2 && B.Destroyer.alreadyPlace == 1){
        cout <<"***Awe. You have destroy computer destroyer ship***" << endl;
        B.Destroyer.alreadyPlace = 0;
    }
        return 0;

}