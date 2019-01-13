//
// Created by khang on 9/29/2018.
//

#include <iostream>
#include <fstream>
#include "Dictionary.h"
using namespace std;


void Dictionary::addWord(DictEntry word) {
    myList.push_back(word);  // Add one node to the right of the last node
}

std::list<DictEntry>::iterator Dictionary::myPtrBegin() {
    myPtr = myList.begin();   //  Pointer point to headPtr points to
    return myPtr;
}

std::list<DictEntry>::iterator Dictionary::myPtrEnd() {
    myPtr = myList.end();  // Pointer point to tailPtr points to
    return myPtr;
}
void Dictionary::sortListIncrease() {
/*    for(auto iter1 = myList.begin(); iter1 != myList.end(); iter1++) {
        for(auto iter2 = iter1; iter2 != myList.end(); iter2++) {
            if( iter2->getWord() < iter1->getWord()){
                DictEntry temp;
                temp = *iter1;
                *iter1 = *iter2;
                *iter2 = temp;
            }
        }
    }
    */
      myList.sort();  // Sort function from smallest to greatest value
}
bool Dictionary::searchFromBegin(DictEntry word){
    // This method search from left to right
    // IF found print index and return true else return false
    int i = 0;
           cout << word.getWord();
            for(auto iter = myList.begin(); iter != myList.end(); iter++){
                i++;
                if(iter->getWord() == word.getWord()){
                    cout << " " << i << " search";
                    return 1;
                }
            }
    cout << " Not found";
    return 0;
}
bool Dictionary::searchFromBack(DictEntry word){
    //Search from right to left
    //If found print index and return true else return false
    int i = 0;
    cout << word.getWord();
    list<DictEntry>::reverse_iterator myPtr;
    for(auto myPtr = myList.rbegin(); myPtr != myList.rend(); myPtr++){
        i++;
        if(myPtr->getWord() == word.getWord()){
            cout << " " << i << " search" << endl;
            return 1;
        }
    }
    cout << "Not found" << endl;
    return 0;
}
void Dictionary::output() {
    //Output list node from left to right
    for(auto myPtr = myList.begin(); myPtr != myList.end(); myPtr++){
       cout << myPtr->getWord() << " ";
        }
        cout << endl;
}
void Dictionary::revsorted(){
    outFile.open("revsorted.txt");
    for(auto myPtr = myList.rbegin(); myPtr != myList.rend(); myPtr++){
        outFile << myPtr->getWord() << " ";

    }
    outFile << endl;
    outFile.close();
}