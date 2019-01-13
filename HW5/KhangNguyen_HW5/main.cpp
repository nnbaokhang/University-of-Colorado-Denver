#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList myPtr;
    int menu;
    while(1) {
        cout << "1.Insert at front" << endl;
        cout << "2.Insert before position" << endl;
        cout << "3.Insert at back" << endl;
        cout << "4.delete at front" << endl;
        cout << "5.delete at position" << endl;
        cout << "6.delete at back" << endl;
        cout << "7.Clear linked list" << endl;
        cout << "8.Output" << endl;
        cout << "0.Exit" << endl;
        cout << "Please input an option:" << endl;
        cin >> menu;
        switch (menu) {
            case 1:{
                char value;

                cout <<"Please input value you want to add:" << endl;
                cin >> value;
                myPtr.insertAtFront(value);
                cout << myPtr;
                cout << endl;
                break;
            }

            case 2:{
                char value;
                int index;
                cout <<"Please input value you want to add:" << endl;
                cin >> value;
                cout <<"Please input index where you want to add:" << endl;
                cin >> index;
                myPtr.insertBeforePosition(value,index);
                cout << myPtr;
                cout << endl;
                break;
            }
            case 3:{
                char value;
                cout <<"Please input value you want to add at back:" << endl;
                cin >> value;
                myPtr.insertAtBack(value);
                cout << myPtr;
                cout << endl;
                break;
            }
            case 4:{
                cout << "Delete at front" << endl;
                myPtr.deleteAtFront();
                cout << myPtr;
                cout << endl;
                break;
            }
            case 5:{
                int index;
                cout <<"PLease tell me where you want do delete:" << endl;
                cin >> index;
                myPtr.deletePosition(index);
                cout << myPtr;
                cout << endl;
                break;
            }
            case 6:{
                cout <<"Delete at back" << endl;
                myPtr.deleteAtBack();
                cout << myPtr;
                cout << endl;
                break;
            }
            case 7:{
                myPtr.clear();
                cout <<"The whole linked list is clear" << endl;
                cout << myPtr;
                break;
            }
            case 8:{
                cout<< myPtr;
                break;
            }

            default: {

                cout << endl;
                break;
            }
        }

        if(menu == 0)
            break;
    }

  cout <<"Program is out" << endl;
    return 0;
}