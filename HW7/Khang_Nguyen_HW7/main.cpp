#include <iostream>
#include <queue>
#include "Teller.h"
#include "Associate.h"
using namespace std;

int main() {
    Teller Line;
    vector<int> Arrival;
    vector<int> Transaction;
    //Only for one line teller
    int menu;
    readDataFromFile(Arrival,Transaction);
    cout << "Press 1 if you want customer entry in one line" << endl;
    cout << "Press 2 if you want customer entry in Line A or Line B or Line C" << endl;
    cout << "Press 0 if you want to end program" << endl;
    cin >> menu;
    while(1) {
        switch (menu) {
            case 1:{
                cout << "Customer can entry only One Line:" << endl;
                processData1(Line,Arrival,Transaction);
                //Customer can only go to a line
                Line.showQ();
                Line.clear();
                break;
            }
            case 2:{
                cout << "Customer may entry Line A, Line B or Line C: " << endl;
                processData2(Line,Arrival,Transaction);
                //Customer may go to Line A , B or C
                Line.showQ();
                Line.clear();
                break;
            }
            default: break;
        }

        if(menu == 0)
            break;
        cout << endl;
        cout << "Press 1 if you want customer entry in one line" << endl;
        cout << "Press 2 if you want customer entry in Line A or Line B or Line C" << endl;
        cout << "Press 0 if you want to end program" << endl;
        cin >> menu;
    }
return 0;

}