//
// Created by khang on 10/27/2018.
//

#include "MenuDriver.h"
using namespace std;
void menu(){
    BSTree<GeneralData, string>* treeActor = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* treePicture = new BSTree<GeneralData, string>;
    BSTree<GeneralData, string>* treeNomination = new BSTree<GeneralData, string>;
    vector<GeneralData> myMovieVec;
    ifstream inFile;
    string fileName;
    char menu;
    cout << "Welcome to database manager" << endl;
    cout << "You have 3 database to manage" << endl;
    cout << "Press 1 to read and manage actor-actress database" << endl;
    cout << "Press 2 to read and manage pictures database" << endl;
    cout << "Press 3 to read and manage nominations database" << endl;
    cout << "Press 0 to exit database manager" << endl;

    cin >> menu;
    while(menu != '0'){
        switch(menu){
            case '1':{
                    fileName = "actor-actress.csv";
                    cout << "Welcome to actor-actress database" << endl;
                    //Go to actor database
                    inFile.open("actor-actress.csv");
                    readFromFile1(inFile, *treeActor, myMovieVec);
                    menuSub(inFile, *treeActor, myMovieVec,fileName);
                    break;
            }
            case '2':{
                    fileName = "pictures.csv";
                    cout << "Welcome to pictures database" << endl;
                    readFromFile2(inFile, *treePicture, myMovieVec);
                    menuSub(inFile, *treePicture, myMovieVec,fileName);
                    break;
            }
            case '3':{
                    fileName = "nominations.csv";
                    cout << "Welcome to nominations database" << endl;
                    inFile.open("nominations.csv");
                    readFromFile1(inFile, *treeNomination, myMovieVec);
                    menuSub(inFile, *treeNomination, myMovieVec,fileName);
                    break;
            }
            default: break;
        }
        cout << "Welcome to database manager" << endl;
        cout << "You have 3 database to manage" << endl;
        cout << "Press 1 to read and manage actor-actress database" << endl;
        cout << "Press 2 to read and manage pictures database" << endl;
        cout << "Press 3 to read and manage nominations database" << endl;
        cout << "Press 0 to exit database manager" << endl;
        cin >> menu;
        myMovieVec.clear();
        }
    if(menu == '0'){
        cout <<"You successfully exit database manager" << endl;
    }
}
void menuSearch1(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* TreePtr,std::string fileName){
        char submenu;
        string field;
        cout <<"Welcome to search in " << fileName << endl;
        cout <<"Input 1 to do search by year" << endl;
        cout <<"Input 2 to do search by name" << endl;
        cout <<"Input 3 to do search by film" << endl;
        cout <<"Input 0 to go back to search" << endl;
        cin >> submenu;
        while(submenu != '0'){
            switch(submenu){
                case '1':{
                    cout << "Doing search by year" << endl;
                    cin.ignore();
                    getline(cin,field);
                    menuSubSearch(tree,TreePtr,"Year",field);
                    cout <<"Please input year you want to search:" << endl;
                    break;
                }
                case '2':{
                    cout << "Doing search by name" << endl;
                    cin.ignore();
                    getline(cin,field);
                    menuSubSearch(tree,TreePtr,"Name",field);
                    break;
                }
                case '3':{
                    cout << "Doing search by film" << endl;
                    cin.ignore();
                    getline(cin,field);
                    menuSubSearch(tree,TreePtr,"Film",field);
                    break;
                }
                default:{
                    break;
                }
            }
            cout <<"Input 1 to do search by year" << endl;
            cout <<"Input 2 to do search by name" << endl;
            cout <<"Input 3 to do search by film" << endl;
            cout <<"Input 0 to go back to search" << endl;
            cin >> submenu;
        }
}

void menuSub(std::ifstream& inFile, BSTree<GeneralData, string>& tree,vector<GeneralData>& myVector,std::string fileName){
    char submenu;
    Node<GeneralData, string>* myTreePtr = tree.Root();
    cout <<"Input 1 to search a record in "<< fileName << endl;
    cout <<"Input 2 to add a record in "<< fileName << endl;
    cout <<"Input 3 to modify a record in "<< fileName << endl;
    cout <<"Input 4 to delete a record in " << fileName << endl;
    cout <<"Input 5 to print out updated of "<< fileName << endl;
    cout <<"Input 6 to do sort in "<< fileName << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                if(fileName == "actor-actress.csv" || fileName == "nominations.csv") {
                    menuSearch1(tree, myTreePtr, fileName);
                }
                else if(fileName == "pictures.csv"){
                    menuSearch2(tree, myTreePtr, fileName);
                }
                cout << "Successful search in " << fileName << endl;
                break;
            }
            case '2':{
                menuAdd(tree,fileName);
                cout << "Successful add in " << fileName << endl;
                break;
            }
            case '3':{
                menuModify(tree,fileName);
                cout << "Successful modify in " << fileName << endl;
                break;
            }
            case '4':{
                menuDelete(tree,fileName);
                cout << "Successful delete in " << fileName << endl;
                break;
            }
            case '5':{
                cout << "Print out file..." << endl;
                printOutFile(tree,tree.Root(),fileName);
                break;
            }
            case '6':{
                cout <<"Welcome to sort..." << endl;
                if(fileName == "actor-actress.csv" || fileName == "nominations.csv") {
                    menuSort1(tree, myVector, fileName);
                }
                else if(fileName == "pictures.csv"){
                    menuSort2(tree,myVector,fileName);
                }
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to search a record in " << fileName <<endl;
        cout <<"Input 2 to add a record in " << fileName << endl;
        cout <<"Input 3 to modify a record in " << fileName << endl;
        cout <<"Input 4 to delete a record in " << fileName  << endl;
        cout <<"Input 5 to print out record in " << fileName << endl;
        cout <<"Input 6 to do sort in " << fileName << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuAdd(BSTree<GeneralData, string>& tree, std::string fileName){
    char submenu;
    cout <<"Welcome to add" << endl;
    cout <<"Input 1 to add new record in " << fileName << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                cout << "add new record in " << fileName << endl;
                addNewRecord(tree,fileName);
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to add new record in " << fileName << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuModify(BSTree<GeneralData, string>& tree,std::string& fileName){
    char submenu;
    cout <<"Welcome to modify" << endl;
    cout <<"Input 1 to modify a record in " << fileName << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                cout << "Modify..." << fileName << endl;
                modifyRecord(tree,fileName);
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to modify a record in " << fileName << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuDelete(BSTree<GeneralData,string>& tree, std::string fileName){
    char submenu;
    cout <<"Welcome to delete" << endl;
    cout <<"Input 1 to delete a record in " << fileName << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                deleteRecord(tree);
                cout << "Successful delete in " << fileName << endl;
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to delete a record in " << fileName << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuSubSearch(BSTree<GeneralData, string>& tree,Node<GeneralData, string>* treePtr,std::string searchField,std::string field){
    char submenu;

    cout <<"Input 1 to do exact search" << endl;
    cout <<"Input 2 to do partial search" << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                exactSearchRecord(tree,treePtr,searchField,field);
                break;
            }
            case '2':{
                partialSearchRecord(tree,treePtr,searchField,field);
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to do exact search" << endl;
        cout <<"Input 2 to do partial search" << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuSort1(BSTree<GeneralData,string>& tree,vector<GeneralData>& myVector,std::string fileName){
    char submenu;
    cout <<"Input 1 to do sort by year" << endl;
    cout <<"Input 2 to do sort by film" << endl;
    cout <<"Input 3 to do sort by name" << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                sortF(myVector,0, myVector.size() - 1,"Year");
                printOutVector(myVector);
                break;
            }
            case '2':{
                sortF(myVector,0, myVector.size() - 1,"Film");
                printOutVector(myVector);
                break;
            }
            case '3':{
                tree.printInorder();
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to do sort by year" << endl;
        cout <<"Input 2 to do sort by film" << endl;
        cout <<"Input 3 to do sort by name" << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuSort2(BSTree<GeneralData,string>& tree,vector<GeneralData>& myVector, std::string fileName){
    char submenu;
    cout <<"Input 1 to do sort by year" << endl;
    cout <<"Input 2 to do sort by film" << endl;
    cout <<"Input 3 to do sort by nominations" << endl;
    cout <<"Input 4 to do sort by rating" << endl;
    cout <<"Input 5 to do sort by genre1" << endl;
    cout <<"Input 0 to go back to main" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                sortF(myVector,0, myVector.size() - 1,"Year");
                printOutVector(myVector);
                break;
            }
            case '2':{
                tree.printInorder();
                break;
            }
            case '3':{
                sortF(myVector,0, myVector.size() - 1,"nominations");
                printOutVector(myVector);
                break;
            }
            case '4':{
                sortF(myVector,0, myVector.size() - 1,"rating");
                printOutVector(myVector);
                break;
            }
            case '5':{
                sortF(myVector,0, myVector.size() - 1,"genre1");
                printOutVector(myVector);
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to do sort by year" << endl;
        cout <<"Input 2 to do sort by film" << endl;
        cout <<"Input 3 to do sort by nominations" << endl;
        cout <<"Input 4 to do sort by rating" << endl;
        cout <<"Input 5 to do sort by genre1" << endl;
        cout <<"Input 0 to go back to main" << endl;
        cin >> submenu;
    }
}
void menuSearch2(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* TreePtr,std::string fileName){
    char submenu;
    string field;
    cout <<"Welcome to search in " << fileName << endl;
    cout <<"Input 1 to do search by year" << endl;
    cout <<"Input 2 to do search by film" << endl;
    cout << "Input 3 to do search by nominations" << endl;
    cout << "Input 4 to do search by genre" << endl;
    cout << "Input 5 to do search by release" << endl;
    cout <<"Input 0 to go back to search" << endl;
    cin >> submenu;
    while(submenu != '0'){
        switch(submenu){
            case '1':{
                cout << "Doing search by year" << endl;
                cin.ignore();
                getline(cin,field);
                menuSubSearch(tree,TreePtr,"Year",field);
                cout <<"Please input year you want to search:" << endl;
                break;
            }
            case '2':{
                cout << "Doing search by film" << endl;
                cin.ignore();
                getline(cin,field);
                menuSubSearch(tree,TreePtr,"Name",field);
                break;
            }
            case '3':{
                cout << "Doing search by nominations" << endl;
                cin.ignore();
                getline(cin,field);
                menuSubSearch(tree,TreePtr,"nominations",field);
                cout <<"Please input year you want to search:" << endl;
                break;
            }
            case '4':{
                cout << "Doing search by genre" << endl;
                cin.ignore();
                getline(cin,field);
                menuSubSearch(tree,TreePtr,"genre",field);
                break;
            }
            case '5':{
                cout << "Doing search by release" << endl;
                cin.ignore();
                getline(cin,field);
                menuSubSearch(tree,TreePtr,"release",field);
                break;
            }
            default:{
                break;
            }
        }
        cout <<"Input 1 to do search by year" << endl;
        cout <<"Input 2 to do search by film" << endl;
        cout << "Input 3 to do search by nominations" << endl;
        cout << "Input 4 to do search by genre" << endl;
        cout << "Input 5 to do search by release" << endl;
        cout <<"Input 0 to go back to search" << endl;
        cin >> submenu;
    }
}