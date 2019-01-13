//
// Created by khang on 11/1/2018.
//
#include "function.h"
#include <string>
using namespace std;
void exactSearchRecord(BSTree<GeneralData, string>& tree,Node<GeneralData,string> * TreePtr,std::string &searchField,std::string& field){
    //Travel entire tree and find if record is match whichever user input
    if(TreePtr == nullptr){
        return;
    }
    exactSearchRecord(tree,TreePtr->Left(),searchField,field);
    if(searchField == "Name") {
        if (TreePtr->Data().Name == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "Film"){
        if (TreePtr->Data().Film == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "Year"){
        if (TreePtr->Data().Year == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "nominations"){
        if (to_string(TreePtr->Data().nominations) == (field)) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "rating"){
        if (to_string(TreePtr->Data().rating) == (field)) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "genre"){
        if (TreePtr->Data().genre1 == field || TreePtr->Data().genre2 == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "release"){
        if (TreePtr->Data().release == field) {
            tree.print(cout, TreePtr->Data());
        }
    }
    exactSearchRecord(tree,TreePtr->Right(),searchField,field);
}

void partialSearchRecord(BSTree<GeneralData, string>& tree,Node<GeneralData,string> * TreePtr,std::string &searchField,std::string& field){
    //Travel entire tree and find if record is partial match whichever user input
    if(TreePtr == nullptr){
        return;
    }
    partialSearchRecord(tree,TreePtr->Left(),searchField,field);
    if(searchField == "Name") {
        if (TreePtr->Data().Name.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "Film"){
        if (TreePtr->Data().Film.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "Year"){
        if (TreePtr->Data().Year.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "nominations"){
        if (to_string(TreePtr->Data().nominations).find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "rating"){
        if (to_string(TreePtr->Data().rating).find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "genre"){
        if (TreePtr->Data().genre1.find(field) != std::string::npos || TreePtr->Data().genre2.find(field) != std::string::npos) {
            tree.print(cout, TreePtr->Data());
        }
    }
    else if(searchField == "release"){
        if (TreePtr->Data().release.find(field) != std::string::npos){
            tree.print(cout, TreePtr->Data());
        }
    }
    partialSearchRecord(tree,TreePtr->Right(),searchField,field);

}

void addNewRecord(BSTree<GeneralData, string>& tree,std::string& fileName){
     GeneralData newRecord;
     if(fileName != "pictures.csv") {
         cout << "Please input your new record as the following" << endl;
         cout << "Year,Award,Winner,Name,Film" << endl;
         cout << "Year:" << endl;
         cin >> newRecord.Year;
         cout << "Award:" << endl;
         cin.ignore();
         getline(cin, newRecord.Award);
         cout << "Winner:" << endl;
         cin >> newRecord.Winner;
         cout << "Name:" << endl;
         cin.ignore();
         getline(cin, newRecord.Name);
         cout << "Film" << endl;
         getline(cin, newRecord.Film);
         tree.addNode(newRecord.Name, newRecord);
     }
     else{
         cout << "Please input your new record as the following" << endl;
         cout << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
         cout << "name:" << endl;
         cin.ignore();
         getline(cin,newRecord.Name);
         cout << "year:" << endl;
         getline(cin, newRecord.Year);
         cout << "nominations:" << endl;
         cin >> newRecord.nominations;
         cout << "rating:" << endl;
         cin >>newRecord.rating;
         cout << "duration:" << endl;
         cin >> newRecord.duration;
         cout <<"genre1:" << endl;
         cin.ignore();
         getline(cin, newRecord.genre1);
         cout <<"genre2:" << endl;
         getline(cin,newRecord.genre2);
         cout <<"release:" << endl;
         getline(cin,newRecord.release);
         cout <<"metacritic:" << endl;
         cin >> newRecord.metacritic;
         cout << "synopsis:" << endl;
         cin.ignore();
         getline(cin,newRecord.synopsis);
         tree.addNode(newRecord.Name, newRecord);
     }
     cout <<"Successful add:" << endl;
     tree.print(cout,newRecord);
}
void deleteRecord(BSTree<GeneralData,string>& tree){
    //Travel the tree to find match record that user want to delete
    cout<<"Please input name of actor you want to delete:" << endl;
    GeneralData record;
    cin.ignore();
    getline(cin,record.Name);
    if(tree.findNode(record.Name) != nullptr) {
        tree.deleteNode(record.Name);
    }
    else{
        cout <<"Record is already deleted or not in database" << endl;
    }
}
void modifyRecord(BSTree<GeneralData,string>& tree, std::string& fileName){
    //Travel the tree and find match record and modify it
    GeneralData changeRecord;
    Node<GeneralData,string> *treePtr;
    string field;
    cout<<"Please input name of record you want to modify. Please input name of actor or actress first:" << endl;
    cin.ignore();
    getline(cin, field);
    treePtr = tree.findNode(field);
    if(treePtr == nullptr){
        cout <<"Record is not exist in database. You can't modify it" << endl;
    }
    else{
        if(fileName == "pictures.csv"){
            int menu;
            cout <<"Record you want to change is in the database" << endl;
            do{
                cout <<"How would you want to change it" << endl;
                cout <<"Input 0 to change name" << endl;
                cout <<"input 1 to change year" << endl;
                cout <<"input 2 to change nominations" << endl;
                cout <<"input 3 to change rating" << endl;
                cout <<"input 4 to change duration" << endl;
                cout <<"input 5 to change genre1" << endl;
                cout <<"input 6 to change genre2" << endl;
                cout <<"input -1 if you want to exit" << endl;
                cin >> menu;
                changeRecord = treePtr->Data();
                switch(menu) {
                    case 0:{
                        cout <<"Input Name. For example: Birdman" << endl;
                        cin.ignore();
                        getline(cin,changeRecord.Name);
                        break;
                    }
                    case 1:{
                        cout <<"Input Year. For example: 2018" << endl;
                        cin >> changeRecord.Year;
                        break;
                    }
                    case 2:{
                        cout << "Input Nominations. Must be an integer" << endl;
                        cin >> changeRecord.nominations;
                        break;
                    }
                    case 3:{
                        cout << "Input rating. Must be a real number" << endl;
                        cin >> changeRecord.rating;
                        break;
                    }
                    case 4:{
                        cout <<"Input duration.Must be a real number" << endl;
                        cin >> changeRecord.duration;
                        break;
                    }
                    case 5:{
                        cout <<"Input genre1. For example: Comedy" << endl;
                        cin >> changeRecord.genre1;
                        break;
                    }
                    case 6:{
                        cout <<"Input genre2. For example: Drama" << endl;
                        cin >> changeRecord.genre2;
                        break;
                        }
                    default:{
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                cout <<"Your modified record is"<< endl;
                tree.print(cout, changeRecord);
            }while(menu != - 1);
        }
        else if(fileName == "actor-actress.csv" || fileName == "nominations.csv"){
            int menu;
            cout <<"Record you want to change is in the database" << endl;
            do{
                cout <<"How would you want to change it" << endl;
                cout <<"Input 0 to change Year" << endl;
                cout <<"input 1 to change Award" << endl;
                cout <<"Input 2 to change winner" << endl;
                cout <<"Input 3 to change name" << endl;
                cout <<"Input 4 to change film" << endl;
                cout <<"input -1 if you want to exit" << endl;
                cin >> menu;
                changeRecord = treePtr->Data();
                switch(menu) {
                    case 0:{
                        cout <<"Input Year. For example: 2018" << endl;
                        cin >> changeRecord.Year;
                        break;
                    }
                    case 1:{
                        cout <<"Input Award." << endl;
                        cin.ignore();
                        getline(cin,changeRecord.Award);
                        break;
                    }
                    case 2:{
                        cout << "Input winner. 0 or 1" << endl;
                        cin >> changeRecord.Winner;
                        break;
                    }
                    case 3:{
                        cout <<"Input Name. For example: Birdman" << endl;
                        cin.ignore();
                        getline(cin,changeRecord.Name);
                        break;
                    }
                    case 4:{
                        cout <<"Input film" << endl;
                        cin.ignore();
                        getline(cin,changeRecord.Film);
                        break;
                    }
                    default:{
                        break;
                    }
                }
                treePtr->setData(changeRecord);
                cout <<"Your modified record is"<< endl;
                tree.print(cout, changeRecord);
            }while(menu != - 1);
        }
        else{
            cout <<"Sorry. File is not exist" << endl;
        }
    }
}
void mergeF(vector<GeneralData>& myVector,int l ,int m,int r,std::string mergeField){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp vector*/
    vector<GeneralData> L, R;

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L.push_back(myVector[l + i]);
    for (j = 0; j < n2; j++)
        R.push_back(myVector[m + 1+ j]);

    /* Merge the temp arrays back into vector*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    if(mergeField == "Film"){
        while (i < n1 && j < n2)
        {
            if (L[i].Film <= R[j].Film)
            {
                myVector[k] = L[i];
                i++;
            }
            else
            {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    else if(mergeField == "Year"){
        while (i < n1 && j < n2)
        {
            if (L[i].Year<= R[j].Year)
            {
                myVector[k] = L[i];
                i++;
            }
            else
            {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    else if(mergeField == "rating"){
        while (i < n1 && j < n2)
        {
            if (L[i].rating<= R[j].rating)
            {
                myVector[k] = L[i];
                i++;
            }
            else
            {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    else if (mergeField == "nominations"){
        while (i < n1 && j < n2)
        {
            if (L[i].nominations<= R[j].nominations)
            {
                myVector[k] = L[i];
                i++;
            }
            else
            {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    else if (mergeField == "genre1"){
        while (i < n1 && j < n2)
        {
            if (L[i].rating<= R[j].rating)
            {
                myVector[k] = L[i];
                i++;
            }
            else
            {
                myVector[k] = R[j];
                j++;
            }
            k++;
        }
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        myVector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        myVector[k] = R[j];
        j++;
        k++;
    }
    L.clear();
    R.clear();
}

void sortF(vector<GeneralData>& myVector, int l , int r, std::string sortField){
    //Merge sort
    if(l < r) {
        int m = l + (r - l) / 2;
        sortF(myVector, l, m, sortField);
        sortF(myVector, m + 1, r, sortField);
        mergeF(myVector,l,m,r, sortField);
    }
}

void printOutFile(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* node, std::string fileName){
    if(node == nullptr)
        return;
    ofstream updateFile;
    if(fileName == "actor-actress.csv" || fileName == "nominations.csv"){
        string name;
        name = "updated" + fileName;
        updateFile.open(name);
    }
    else if (fileName == "pictures.csv"){
        string name;
        name = "updated" + fileName;
        updateFile.open(name);
    }

    printRecursive(tree,node,updateFile);

   cout <<"Sucessfully print out" << endl;
   updateFile.close();
}
void printRecursive(BSTree<GeneralData, string>& tree,Node<GeneralData,string>* node,std::ofstream& updateFile){
    if(node == nullptr)
        return;
    printRecursive(tree,node->Left(),updateFile);
    tree.print(updateFile,node->Data());
    printRecursive(tree,node->Right(),updateFile);
}
void printOutVector(vector<GeneralData>& myVector){
    for( auto i : myVector){
        if(i.synopsis == "")
            cout << i.Year << "," << i.Award << "," << i.Winner <<"," << i.Name << "," << i.Film << endl;
        else {
            cout <<i.Name << "," << i.Year << "," << i.nominations <<"," << i.rating << "," << i.duration<<
                       "," << i.genre1 << "," << i.genre2 << "," << i.release << "," << i.metacritic <<"," << i.synopsis
                       << endl;
        }
    }
}
