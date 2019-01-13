/*
 * Khang Nguyen
 */
#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream>
#include <algorithm>
#include"hashTable.h"
using namespace std;

int main() {

    hashTable myHash;
    ifstream myFile("dict.txt");
    ifstream checkFile;
    if(!myFile.is_open()){
        cout <<"File is not open" << endl;
        return 0;
    }
    //Make hash table
    string myStr;
    while(getline(myFile,myStr)){
        transform(myStr.begin(), myStr.end(), myStr.begin(), ::tolower);// String to lower case
        myHash.add(myStr);
    }
    //Check variable
    int wordInfile = 0,countWord = 0,missSpell = 0;
    string menu;
     cout <<"Please enter file you want to check" << endl;
     cout <<"Input check to open check.txt" << endl;
     cout <<"Input Potter to open Potter.txt" << endl;
     cin >> menu;
     checkFile.open(menu+".txt");
    if(!checkFile.is_open()){
        cout <<"Check file is not open" << endl;
        return 0;
    }
    else{
        cout << menu <<".txt is open" << endl;
    }
    //Doing check job
     checkFileWord(checkFile,myHash,wordInfile,countWord,missSpell);
cout << myHash.numberOfWord <<" dictionary words, "<< wordInfile
       <<" words in file, " << missSpell << " misspelled";

    return 0;

}