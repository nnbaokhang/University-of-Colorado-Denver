#include <iostream>
#include <fstream>
#include <list>
#include "DictEntry.h"
#include "Dictionary.h"
#include "DoublyLinkedList.h"
using namespace std;
ofstream outFile; // Global variable

int main() {

    ifstream myFile, wordFile;
    string myString;
    Dictionary myDic1;
    DictEntry word;
    DoublyLinkedList myDic2;
    int menu;
    cout << "1.Using STL doubly linked list."<< endl;
    cout << "2.Using non STL doubly linked list." << endl;
    cout << "0.Exit." << endl;
    cin >> menu;

        switch (menu) {
            case 1: {
                myFile.open("dictionary.txt"); //File open
                if (!myFile.is_open()) {
                    cout << "Nothing is here" << endl;
                } else {
                    while (getline(myFile, myString)) {
                        word.setWord(myString); // Define a DicEntry Node
                        myDic1.addWord(word);   // Add node into list
                    }
                    myFile.close(); //File close
                }
                myDic1.sortListIncrease();  // Sort from lowest to highest
                myDic1.output(); // Output each node
                myDic1.revsorted(); // Write to file
                wordFile.open("findwords.txt"); //File open
                if (!wordFile.is_open()) {
                    cout << "Nothing is here" << endl;
                } else {
                    cout << "Search from begin" << endl;
                    while (getline(wordFile, myString)) {
                        word.setWord(myString);  // Define a DicEntry Node
                        myDic1.searchFromBegin(word); // Searchfrom left to right
                        cout << endl;

                    }
                    wordFile.close(); // File close
                    wordFile.open("findwords.txt"); // File open
                    cout << endl;
                    cout << "Search from back" << endl;
                    while (getline(wordFile, myString)) {
                        word.setWord(myString);
                        myDic1.searchFromBack(word);
                    }
                    wordFile.close(); // File close
                }
                break;
            }
            case 2: {
                myFile.open("dictionary.txt");  //File open
                if (!myFile.is_open()) {
                    cout << "Nothing is here" << endl;
                } else {
                    while (getline(myFile, myString)) {

                        word.setWord(myString);  // Define node
                        myDic2.addWord(word); // Add node to linked list
                    }
                    myFile.close(); // File close

                myDic2.sortListIncrease(); // Sort smallest to highest
                myDic2.output(); // Output
                myDic2.revsorted(); // Write to file
                cout << endl;
                wordFile.open("findwords.txt"); // File open
                if (!wordFile.is_open()) {
                    cout << "Nothing is here" << endl;
                } else {
                    cout << "Search from begin" << endl;
                    while (getline(wordFile, myString)) {
                        word.setWord(myString);     // Define node
                        myDic2.searchFromBegin(word); // Search that node in linked list from left to right
                    }
                    wordFile.close(); // File close
                    wordFile.open("findwords.txt"); // File open
                    cout << endl;
                    cout << "Search from back" << endl;
                    while (getline(wordFile, myString)) {
                        word.setWord(myString);   // Define node
                        myDic2.searchFromBack(word);// Search that node in linked list from right to left
                    }
                    wordFile.close(); // File close
                }
                    break;
                }
                default:
                    break;
            }
        }
    return 0;
}