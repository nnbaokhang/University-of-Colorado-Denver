//
// Created by khang on 10/7/2018.
//This computerGrid inherit from Base class
//Also this is for computer it should have set its location by a computer
// Friend function AfireatB allows user to access computer member variables and functions
//

#ifndef BATTLESHIP_COMPUTERGRID_H
#define BATTLESHIP_COMPUTERGRID_H

#include "Ship.h"
#include "Base.h"
class computerGrid:public Base{

public:
    bool setLocation();//
    //Input none
    //Set computer'ship in grid
    //Output return 1 if set up successful
    //Return 0 if set up unsuccessful
    friend int AfireatB(int X ,int Y, computerGrid& B,std::string a[10][10]);
    //Input need to be valid
    //Output doing A fight at B
    //Output ship that being destroyed
};

#endif //BATTLESHIP_COMPUTERGRID_H
