//
// Created by khang on 9/29/2018.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <list>
#include "DictEntry.h"
extern std::ofstream outFile;
class Dictionary {
private:
    std::list<DictEntry> myList;  // Create a list that contain DictEntry node
    std::list<DictEntry>::iterator myPtr; // Pointer of list from left to right
public:
   Dictionary(){}; // Default constructor;
   void addWord(DictEntry word); // Add one node to list
   std::list<DictEntry>::iterator myPtrBegin(); // Iterator from the headPtr
   std::list<DictEntry>::iterator myPtrEnd();// Iterator from tailPtr
   void sortListIncrease();   // Sort list ascending
   bool searchFromBegin(DictEntry word); // Search from left to right
   bool searchFromBack(DictEntry word); // Search from right to left
   void output(); // Output the list from left to right
   void revsorted();  // Reverse the list from right to left

};


#endif //HW6_DICTIONARY_H
