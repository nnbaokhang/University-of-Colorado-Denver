//
// Created by khang on 8/31/2018.
//

#include "SetFunctions.h"
#include<iostream>
#include <sstream>
using namespace std;
bool getIntsFromFile(ifstream& infile, vector<int> &vec)
//istream accepts from cin or file as a parent class
{
    stringstream ss;
    int tempInt;
    string readString;

    getline(infile, readString);
    ss << readString; //Write readString into ss
    while (!ss.eof()) //Until end of stream
    {
        ss >> tempInt; //Read in an int from ss into tempInt
        if (ss.fail()) //If it fails to read an int data type
        {
            cout << "Input contains non-integer data\n";
            ss.clear(); //Clears state of string stream;
            return false;
        }
        vec.push_back(tempInt); //Add to the vector

    }

    return true;
}

/*Desc: Prints out all values in a vector
  Pre: Reads in a vector
  Post: void
*/
void printValues(vector<int> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        cout << set[i] << " ";
    }
    cout << endl;
}