//
// Created by khang on 10/7/2018.
//This Ship struct contains member variables a ship should have
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H
#include <string>
struct Ship{
    int length;
    int Y;// is column
    int X; //  is row
    char Z; //Horizontal or vertical
    std::string symbol;
    bool alreadyPlace = 0;
};
#endif //BATTLESHIP_SHIP_H
