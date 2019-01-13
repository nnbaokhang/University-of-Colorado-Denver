/* This program need to use + operator and - operate to add and delete number from the set
 * No duplicate number
 * Credit to Khang Nguyen
 */

#include <iostream>
#include <sstream>      //stringstream
#include <string> //ifstream
#include <vector>
#include <fstream>
#include "SetFunctions.h"
#include "ArrayBag.h"
using namespace std;


int main() {
    // Read file
    ifstream file;
    vector<int> set1, set2;
    ArrayBag A, B, C;
    int menu;


    cout << "Open set of integer numbers press 1" << endl;
    cout << "OPen set of non integer press 2" << endl;
    cin >> menu;
    switch(menu){
        case 1: file.open("setInput.txt");
        break;
        case 2: file.open("setNonIntegerInput.txt");
        break;

    }
    //Check if file is opened
    if(file.is_open()) {
        if (getIntsFromFile(file, set1)) {
            // Store data in ArrayBag variable A and B
            for (int i = 0; i < set1.size(); i++)
                A.add(set1[i]);

        }
        else
        {
            cout<< "Invalid input" << endl;
            return 0;
        }
        if (getIntsFromFile(file, set2)) {

            for (int i = 0; i < set2.size(); i++)
                B.add(set2[i]);
        }
        else{
            cout << "Invalid input" << endl;
            return 0;
            }
    }
    else {
        cout << "File is not open" << endl;
        return 0;
    }

    C= A + B;
    cout << "The union of A and B:";
    C.printOut(C);
    cout << endl;
    C.clear();

    cout <<"The difference of A and B:";
    C = A - B;
    C.printOut(C);
    cout << endl;
    C.clear();
    file.close();
  return 0;
}