//
// Created by khang on 10/27/2018.
//

#include "readFromFile.h"
#include "BSTree.hpp"
using namespace std;
void readFromFile1(std::ifstream& inFile,BSTree<GeneralData, string>& tree,vector<GeneralData>& myVector){
    string s;
    GeneralData tempData;
    getline(inFile,s);
    cout << "Adding Nodes...\n";
    while(getline(inFile,s)){
        int size;
        string sub;
        {
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Year = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Award = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Winner = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            tempData.Name = sub;
            s = s.substr(size + 1);
            sub = s;
            tempData.Film = sub;

            tree.addNode(tempData.Name, tempData);
            myVector.push_back(tempData);

        }
    }
    inFile.close();
}
void readFromFile2(std::ifstream& inFile, BSTree<GeneralData, string>& tree,vector<GeneralData>& myVector){
    inFile.open("pictures.csv");
    string s;
    GeneralData tempData;
    getline(inFile,s);
    cout << "Adding Nodes...\n";
    while(getline(inFile,s)){
        int size;
        string sub;
        {
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Name = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.Year = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.nominations = atoi(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            tempData.rating = stof(sub.c_str());
            s = s.substr(size + 1);
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.duration = stof(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.genre1 = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.genre2 = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.release = sub;
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.metacritic = atoi(sub.c_str());
            size = s.find(',');
            sub = s.substr(0, size);
            s = s.substr(size + 1);
            tempData.synopsis = sub;
            tree.addNode(tempData.Name, tempData);
            myVector.push_back(tempData);


        }
    }
    inFile.close();
}
