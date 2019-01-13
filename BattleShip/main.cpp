#include <iostream>
#include <ctime>
#include "playerGrid.h"
#include "computerGrid.h"
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string AIGrid[10][10] = {
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"} ,
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"}
    };
    string PlayerGrid[10][10] = {
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"},   {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"} ,  {"-","-","-","-","-","-","-","-","-","-"},
            {"-","-","-","-","-","-","-","-","-","-"} , {"-","-","-","-","-","-","-","-","-","-"}
    };

    //  column, row
    srand(time(0));
    //Please set up your ship locatioon
    //Please input coordinate of your ship
    //X axis , Y axis and horizon, vertical

   //Need a while loop to fire
   // Can stop when user want to
   //Player fire first then computer then alternatively
   // Need to connect player A to board B
   //Check if position same at ship on board B
   //Relationship between function
   fstream infile ("ship_placement.csv");
   char  colums , direction;
   string typeOfShip;
   int rows;
   playerGrid A;

    if(!infile.is_open()){
       cout << "File is not open" << endl;
       return 0;
   }
    string myData;
    int check = 1;
    //Get data from file
   while(getline(infile, myData)) {
       //Set A location
       int size;
       string sub;
       size = myData.find(',');
       sub = myData.substr(0,size);
       typeOfShip  = sub;
       myData = myData.substr(size+1);
       size = myData.find(',');
       sub = myData.substr(0,size);
       colums = sub[0];
       rows = int(sub[1]) - 48;
       myData = myData.substr(size+1);
       direction = myData[0];
       int columsInt = colums - 65;
       check = A.setLocation(typeOfShip,rows,columsInt,direction);
        if(check == 0) {
            A.outputGrid();
            cout << "Set up failure. Proceed to exit..." << endl;
            return 0;
        }
   }
   cout << "Player Grid" << endl;
   A.getGrid(PlayerGrid);
   A.outputFightGrid(PlayerGrid);
   cout <<"Computer Grid" << endl;
   computerGrid B;
   //Set B location
   B.setLocation();
   B.outputFightGrid(AIGrid);
   string exitC = "C";
   while(exitC != "Q"){
      char Y, X;
       int playWin = 0 , computerWin = 0;
       //Player hit computer;
       cout <<"Human. Please hit your enemy:" << endl;
       do {
           //Check if input is valid{
               cout << "Please input x from A to J | y from 0 to 9" << endl;
               cin >> Y >> X;

       }while(Y < 'A' || Y > 'J' || X < '0' || X > '9');

       playWin = AfireatB(X - 48,Y - 65,B,AIGrid);
       //Computer hit player
       computerWin = BfireatA(A,PlayerGrid);
       //Output player grid
       cout <<"Player Grid" << endl;
       A.outputFightGrid(PlayerGrid);
       //Output computer grid
       cout << "Computer Grid" << endl;
       B.outputFightGrid(AIGrid);

       if(playWin == 1){
           cout << "you defeat computer" << endl;
           cout <<"Player Grid"<< endl;
           A.outputGrid();
           cout <<"Computer Grid" << endl;
           B.outputGrid();
           break;
       }
       else if(computerWin == 1){
           {
               cout << "Computer defeat you" << endl;
               cout <<"PlayerGrid" << endl;
               A.outputGrid();
               cout <<"Computer Grid" << endl;
               B.outputGrid();
               break;
           }
       }
    cout <<"Enter Q if you want to quit." << endl;
       cin >> exitC;
       if(exitC == "Q"){
           cout <<"Computer Grid" << endl;
           B.outputGrid();
           cout <<"You successfully exit" << endl;
           break;
       }
   }
return 0;
    }