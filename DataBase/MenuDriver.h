//
// Created by khang on 10/27/2018.
//

#ifndef DATABASE_MENUDRIVER_H
#define DATABASE_MENUDRIVER_H
#include <iostream>
#include <vector>
#include <fstream>
#include "readFromFile.h"
#include "function.h"
void menu();
//Main menu
void menuSub(std::ifstream& inFile, BSTree<GeneralData, string>& tree,vector<GeneralData>& myVector,std::string fileName);
//Sub main contain add, search, delete, modify menu
void menuSearch1(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* TreePtr,std::string fileName);
// menu search for actor-actress.csv and nominations.csv
void menuSearch2(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* TreePtr,std::string fileName);
// menu search for pictures.csv
void menuAdd(BSTree<GeneralData, string>& tree, std::string fileName);
// menu add new record
void menuModify(BSTree<GeneralData, string>& tree, std::string&fileName);
// menu modify existing record
void menuDelete(BSTree<GeneralData,string>& tree, std::string fileName);
// menu delete existing record
void menuSort1(BSTree<GeneralData,string>& tree,vector<GeneralData>& myVector, std::string fileName);
// menu sort for actor-actress.csv and nominations.csv
void menuSort2(BSTree<GeneralData,string>& tree,vector<GeneralData>& myVector, std::string fileName);
// menu sort for pictures.csv
void menuSubSearch(BSTree<GeneralData, string>& tree,Node<GeneralData, string>* treePtr,std::string searchField, std::string field);
// menu sub search which search contain and partial


#endif //DATABASE_MENUDRIVER_H
