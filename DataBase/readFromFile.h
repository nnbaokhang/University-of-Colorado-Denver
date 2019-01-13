//
// Created by khang on 10/27/2018.
//

#ifndef DATABASE_READFROMFILE1_H
#define DATABASE_READFROMFILE1_H
#include <fstream>
#include <iostream>
#include <vector>
#include "BSTree.h"

void readFromFile1(std::ifstream& inFile, BSTree<GeneralData, string>& tree,vector<GeneralData>& myVector);
void readFromFile2(std::ifstream& inFile, BSTree<GeneralData, string>& picTree,vector<GeneralData>& myVector);
#endif //DATABASE_READFROMFILE1_H
