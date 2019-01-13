//
// Created by khang on 10/21/2018.
//

#include "Base.h"
//
// Created by khang on 9/29/2018.
//
#include "playerGrid.h"
#include"computerGrid.h"
using namespace std;


Base::Base() {

    Carrier.length = 5;
    Carrier.symbol = "Carrier";
    BattleShip.length = 4;
    BattleShip.symbol = "Battleship";
    Cruiser.length = 3;
    Cruiser.symbol = "Cruiser";
    Submarine.length = 3;
    Submarine.symbol = "Submarine";
    Destroyer.length = 2;
    Destroyer.symbol = "Destroyer";

    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10; j++){
            grid[i][j]= "-";
        }
    }

}



bool Base::setLocation(std::string symbol, int X, int Y,char Z) {
    if(symbol != "Carrier" && symbol != "Battleship" && symbol != "Cruiser"&& symbol !=  "Submarine"&&symbol != "Destroyer")
        return 0;

    if(symbol == "Carrier") {
        Carrier.X = X;
        Carrier.Y = Y;
        Carrier.Z = Z;
        if(checkSpace(X,Y,Z,Carrier.length) && Carrier.alreadyPlace == 0) {
            fillGrid("C", X, Y, Z, Carrier.length);
            Carrier.alreadyPlace = 1;
            cout << "Successful set up " << symbol << endl;
            return 1;
        }
    }
    else if(symbol =="Battleship"){
        BattleShip.X=X;
        BattleShip.Y=Y;
        BattleShip.Z=Z;
        if(checkSpace(X,Y,Z,BattleShip.length) && BattleShip.alreadyPlace == 0) {
            fillGrid("B", X, Y, Z, BattleShip.length);
            BattleShip.alreadyPlace = 1;
            cout << "Successful set up " << symbol << endl;
            return 1;
        }
    }
    else if(symbol == "Cruiser"){
        Cruiser.X = X;
        Cruiser.Y = Y;
        Cruiser.Z = Z;
        if(checkSpace(X,Y,Z,Cruiser.length) && Cruiser.alreadyPlace == 0) {
            fillGrid("R", X, Y, Z, Cruiser.length);
            Cruiser.alreadyPlace = 1;
            cout << "Successful set up " << symbol << endl;
            return 1;
        }
    }
    else if(symbol == "Submarine"){
        Submarine.X = X;
        Submarine.Y = Y;
        Submarine.Z = Z;
        if(checkSpace(X,Y,Z,Submarine.length)&& Submarine.alreadyPlace == 0) {
            fillGrid("S", X, Y, Z, Submarine.length);
            Submarine.alreadyPlace = 1;
            cout << "Successful set up " << symbol << endl;
            return 1;
        }
    }
    else if(symbol == "Destroyer"){
        Destroyer.X = X;
        Destroyer.Y = Y;
        Destroyer.Z = Z;
        if(checkSpace(X,Y,Z,Destroyer.length)&& Destroyer.alreadyPlace == 0){
            fillGrid("D",X,Y,Z,Destroyer.length);
            Destroyer.alreadyPlace = 1;}
        cout << "Successful set up " << symbol << endl;
        return 1;
    }
    cout <<"Set up failure. Try again." << endl;
    return 0;
}
bool Base::checkSpace(int X, int Y,char Z, int length){
    if(grid[X][Y] != "-")
        return 0;
    else if(Z == 'H'){
        if(Y + length - 1 >= 10)
            return 0;
        for(int i =  Y; i < Y + length; i++){
            if(grid[X][i] != "-" )
                return 0;
        }
    }
    else if(Z == 'V'){
        if(X + length - 1 >= 10)
            return 0;
        for(int i = X ; i < X + length ; i++){
            if(grid[i][Y] != "-" )
                return 0;
        }
    }
    return 1;
}
void Base::fillGrid(std::string symbol,int X, int Y,char Z,int length){
    if(Z == 'H'){
        for(int i =  Y; i < Y + length; i++){
            grid[X][i] = symbol;
        }
    }
    else if(Z == 'V'){
        for(int i = X ; i < X + length ; i++){
            grid[i][Y] = symbol;
        }
    }

}
void Base::outputGrid(){
    int rows = 0;
    cout << " ";
    for( char cols = 'A'; cols <= 'J' ; cols++)
        cout << "  " << cols;
    cout << endl;
    for(int i = 0 ; i < 10; i++){
        cout  << rows++ << "  ";
        for(int j = 0 ; j < 10; j++){
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}


bool Base::isAlreadyHit(int X, int Y,std::string a[10][10]) {
    if(a[X][Y] == "X" || a[X][Y] == "0")
        return 1;
    return 0;
}
void Base::status(int X,int Y){

    if(grid[X][Y] == "C") {
        Carrier.length--;
    }
    else if(grid[X][Y] == "R") {
        Cruiser.length--;
    }
    else if(grid[X][Y] == "B") {
        BattleShip.length--;
    }
    else if(grid[X][Y] == "S") {
        Submarine.length--;
    }
    else if(grid[X][Y] == "D") {
        Destroyer.length--;
    }
}
bool Base::check(int X,int Y) {
    if(grid[X][Y] == "-")
        return 0;
    else
        return 1;
}
void Base::shipDestroy(std::string a[10][10]){
    if(Carrier.length < 5){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == "C")
                    a[i][j] ="X";
            }
        }
    }
    if(Cruiser.length < 3){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == "R")
                    a[i][j] = "X";
            }
        }
    }
    if(BattleShip.length < 4){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == "B")
                    a[i][j] = "X";
            }
        }
    }
    if(Submarine.length  < 3){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == "S")
                    a[i][j] = "X";
            }
        }
    }
    if(Destroyer.length < 2){
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0; j < 10; j++){
                if(grid[i][j] == "D")
                    a[i][j] = "X";
            }
        }
    }
}
void Base::outputFightGrid( std::string a[10][10]){
    int rows = 0;
    cout << " ";
    for( char cols = 'A'; cols <= 'J' ; cols++)
        cout << "  " << cols;
    cout << endl;
    for(int i = 0 ; i < 10; i++){
        cout  << rows++ << "  ";
        for(int j = 0 ; j < 10; j++){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}
