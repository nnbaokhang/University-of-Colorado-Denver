//
// Created by khang on 11/5/2018.
//

#ifndef HW9_HASHTABLE_H
#define HW9_HASHTABLE_H
#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream>
#include <algorithm>
struct item{
    int key;
    std::string value;
    item* next; // Linked list at index i
};
const int CAPACITY = 1373;
class hashTable {
private: item* hashMap[CAPACITY]; // Use to access hash table
public:
    int numberOfWord  = 0;
    //Default constructor
    hashTable();
    //Add hash table
    void add(std::string value);
    //Print hash table
    void printHashTable();
    //Search if string is in hashtable or not
    bool search(std::string inputSearch);
    //Use algorithm to find a reasonable key for value
    int hashFunction(std::string value);

};
//Check if an input is string or not
bool isString(std:: string x);
//Doing algorithm for counting word
void checkFileWord(std::ifstream &checkFile,hashTable myHash, int &wordInfile,int &count,int &missSpell);

#endif //HW9_HASHTABLE_H
