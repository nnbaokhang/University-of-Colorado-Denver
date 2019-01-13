//
// Created by khang on 11/1/2018.
//

#ifndef DATABASE_FUNCTION_H
#define DATABASE_FUNCTION_H
#include<iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "BSTree.hpp"
void addNewRecord(BSTree<GeneralData, string>& tree,std::string& fileName);
//Pre: Record is not yet exist in database
//Add new record into database
//Post: add a new record to database
void deleteRecord(BSTree<GeneralData,string>& tree);
//Pre:Record is exist in database
//Delete existing record
//Post: delete a record in database
void modifyRecord(BSTree<GeneralData,string>& tree, std::string& fileName);
//Pre:Record is exist in database
//Modify existing record
//Post: modify a record in database
void partialSearchRecord(BSTree<GeneralData, string>& tree,Node<GeneralData,string> * TreePtr,std::string& searchField,std::string& field);
//Pre: Record is exist in database
//Partial search every record in database
//Post output records that match
void exactSearchRecord(BSTree<GeneralData, string>& tree,Node<GeneralData,string> * TreePtr,std::string &searchField,std::string& field);
//Exact search every record in database
//Post output records that match
void sortF(vector<GeneralData>& myVector,int l ,int r,std::string sortField);
//Merge sort. Credit by https://en.wikipedia.org/wiki/Merge_sort
void mergeF(vector<GeneralData>& myVector,int l ,int m,int r, std::string mergeField);
//Merge sort. Credit by https://en.wikipedia.org/wiki/Merge_sort
void printOutFile(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* node, std::string fileName);
//Pre: filename is exist
//Post output every record in database to new file
void printRecursive(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* node,std::ofstream& updateFile);
//Recursively print out the tree
void printOutVector(vector<GeneralData>& myVector);
//Pre: myVector contain every single record in database
//Post output every record to console
#endif //DATABASE_FUNCTION_H
