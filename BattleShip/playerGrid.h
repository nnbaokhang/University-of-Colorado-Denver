//
// Created by khang on 9/29/2018.
//This playerGrid class inherit from base class
//PlayerGrid class contains friend function that allow BfireatA function to access playerGrid member variable
//and member function
//

#ifndef BATTLESHIP_MYGRID_H
#define BATTLESHIP_MYGRID_H

#include <iostream>
#include "Base.h"
class playerGrid:public Base{

public:
    friend int BfireatA(playerGrid& A,std::string a[10][10]);
    //Input need to be valid
    //Output doing B fight at A
    //Output ship that being destroyed
    void getGrid(std::string a[10][10]);
    //Input will be playerFightGrid
    //Output assign playerFightGrid with playerGrid
};





#endif //BATTLESHIP_MYGRID_H
