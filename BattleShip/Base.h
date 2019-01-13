//
// Created by khang on 10/21/2018.
//This is Base class which has every elements that player need to play such as create ship,
//set position and show ships
//

#ifndef BATTLESHIP_BASE_H
#define BATTLESHIP_BASE_H
#include <iostream>
#include "Ship.h"
class Base:public Ship{
protected:
    std::string grid[10][10];
    Ship Carrier, BattleShip, Cruiser, Submarine, Destroyer;
public:
    Base();
    // X must be
    bool setLocation(std::string symbol, int X, int Y,char Z);
    //Input need to be valid in order to process
    //Output will set location of each ship
    //Return 1 if set up success
    //Return 0 if set up not success
    bool checkSpace(int X, int Y,char Z,int length);
    //Input need to be valid in order to process
    //Output
    //Return 1 if space is not yet occupied
    //Return 0 if space is already occupied
    void fillGrid(std::string symbol,int X, int Y,char Z,int length);
    //Input need to be valid in order to process
    //Output fill ship in grid
    //
    void outputGrid();
    //Input none
    //Output the grid
    bool check(int X,int Y);
    //Input need to be valid in order to process
    //Output
    //Return 1 if at (x,y) already occupied
    //Return 0 if at (x,y) not yet occupied
    bool isAlreadyHit(int X, int Y,std::string a[10][10]);
    //Input need to be valid in order to process
    //Output if at (x,y) already hit return 1
    //if at (x,y) not yet hit return 0
    void status(int X,int Y);
    //Input need to be valid in order to process
    //Output reduce each ship length associate with isALreadyHit function
    void shipDestroy(std::string a[10][10]);
    //Input need to be valid in order to process
    //Output ship is destroyed
    void outputFightGrid(std::string a[10][10]);
    //Input need to be valid in order to process
    //Output hidden grid which do not contain origin grid set up for players
};


#endif //BATTLESHIP_BASE_H
