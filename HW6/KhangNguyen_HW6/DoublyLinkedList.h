//
// Created by khang on 10/1/2018.
//

#ifndef HW6_DOUBLYLINKEDLIST_H
#define HW6_DOUBLYLINKEDLIST_H

#include "DictEntry.h"
extern std::ofstream outFile;
// Node
struct Node{
    DictEntry words;
    Node* nextPtr;
    Node* prevPtr;
};
// DoublyLinkedList contains many Node
class DoublyLinkedList{
private:
    Node* headPtr; // head pointer
    Node* tailPtr; // tail pointer
    int size = 0; // size where there is no node = 0
public:
    DoublyLinkedList(){headPtr = nullptr; tailPtr = nullptr; size = 0;}; // Default constructor
    ~DoublyLinkedList(){}; // Destructor;
    void addWord(DictEntry word); // Add one node to list
    void sortListIncrease();  // Sort smallest to greatest element in list
    bool searchFromBegin(DictEntry word); // Search from left to right
    bool searchFromBack(DictEntry word); // Search from right to left
    void output(); //Output from left to right
    void revsorted();  // Reverse the list from right to left
};


#endif //HW6_DOUBLYLINKEDLIST_H
