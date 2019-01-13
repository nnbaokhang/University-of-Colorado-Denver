//
// Created by khang on 10/1/2018.
//
#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"
using namespace std;
void DoublyLinkedList::addWord(DictEntry word){
    //If there is no node then connect one new node to head and tail
    // Also node point to next = nullptr and node point to previous = nullptr
    //Size increase by 1
    if(headPtr == nullptr){
        Node* newPtr = new Node;
        newPtr->words = word;
        headPtr = newPtr;
        tailPtr = newPtr;
        newPtr->prevPtr = nullptr;
        newPtr->nextPtr = nullptr;
        size++;
    }
    //If list exist more than one node
    //Add new node to the end of list
    //Use tailPtr to add that one node
    //Time will be constant
    //Size increase by 1
    else{
        Node* newPtr = new Node;
        Node* temptPtr = tailPtr;
        newPtr->words = word;
        newPtr->prevPtr = tailPtr;
        temptPtr->nextPtr = newPtr;
        tailPtr = newPtr;
        newPtr->nextPtr = nullptr;
        size++;
    }
}
void DoublyLinkedList::output(){
    //Displace each word from left to right
    Node* myPtr;
    myPtr = headPtr;
     while(myPtr != nullptr){
         cout << myPtr->words.getWord() << " ";
         myPtr = myPtr->nextPtr;
     }
}
void DoublyLinkedList::sortListIncrease(){
//Sort list increasing in value
    for(Node* myPtr1 = headPtr; myPtr1 != nullptr; myPtr1 = myPtr1->nextPtr){
        for(Node* myPtr2 = myPtr1 ; myPtr2 != nullptr; myPtr2 = myPtr2->nextPtr){
            if(myPtr2->words < myPtr1->words){
                DictEntry tempt;
                tempt  = myPtr1->words;
                myPtr1->words = myPtr2->words;
                myPtr2->words= tempt;
            }
        }
    }
}
bool DoublyLinkedList::searchFromBegin(DictEntry word){
    //Search from left to right
    //If found print and return true else return false
int i = 0;
    cout << word.getWord();
    for(Node* myPtr1 = headPtr; myPtr1 != nullptr; myPtr1 = myPtr1->nextPtr){
        i++;
        if(myPtr1->words.getWord() == word.getWord()){
            cout << " " << i << " search" << endl;
            return 1;
        }
    }
    cout << " Not found" << endl;
    return 0;
}
bool DoublyLinkedList::searchFromBack(DictEntry word){
    //Search from right to left
    //If found print and return true else return false
int i = 0;
    cout << word.getWord();
    for(Node* myPtr1 = tailPtr; myPtr1 != nullptr; myPtr1 = myPtr1->prevPtr){
        i++;
        if(myPtr1->words.getWord() == word.getWord()){
            cout << " " << i << " search" << endl;
            return 1;
        }
    }
    cout << " Not found" << endl;

    return 0;
}
void DoublyLinkedList::revsorted(){
    outFile.open("revsorted.txt");
    Node* myPtr;
    myPtr = tailPtr;
    while(myPtr != nullptr){
        outFile << myPtr->words.getWord() << " ";
        myPtr = myPtr->prevPtr;
    }
    outFile.close();
}