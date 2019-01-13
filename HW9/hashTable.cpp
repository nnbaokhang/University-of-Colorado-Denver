//
// Created by khang on 11/5/2018.
//
#include "hashTable.h"
using namespace std;
hashTable::hashTable() {
    for(int i = 0 ; i < CAPACITY; i++){
       hashMap[i] = new item;
       hashMap[i]->value = "";
       hashMap[i]->key = -1;
       hashMap[i]->next = nullptr;
    }
}
int hashTable::hashFunction(std::string value){
    //abcd  a* 100 + b* 100 +c * 10 + d
    //dcba  d*1000 + c*100 + b* 10 +c
    //Algorithm to find approriate index
    unsigned int sum = 0;
    for(int i = value.size()-1 ; i >= 0;i--){
        if(value[i] == '.' || value[i] ==',' || value[i] == 39)
         continue;
        sum += value[i];
        sum *= 10;
    }
    return sum % CAPACITY;
}
void hashTable::add(std::string value){
     //Check if word is in the file
    int hash_val = hashFunction(value);
    //If at position i still vacant
    if(hashMap[hash_val]->value == ""){
        hashMap[hash_val]->value = value;
    }
    else{
        //If at position i not vacant then go to linked list
        //at hashtable[i] and go to nullptr and add
        item* myPtr = hashMap[hash_val];
        while(myPtr->next != nullptr){
            myPtr = myPtr->next;
        }
        //Allocate a node
        item* newPtr = new item;
        newPtr->value = value;
        newPtr->next = nullptr;
        myPtr->next = newPtr;
    }
    numberOfWord++;
}
void hashTable::printHashTable(){
    //Go from 0 to capacity
    //Check if each index has a linked list
    //Print out
    item* myPtr;
    for(int i = 0 ; i < CAPACITY; i++){
        cout << i << " " << hashMap[i]->value;
        myPtr = hashMap[i]->next;
        while(myPtr!= nullptr){
            cout << "--" << myPtr->value;
            myPtr = myPtr->next;
        }
        cout << endl;
    }
}
bool hashTable::search(const std::string inputSearch){
    //Search
    int hash_val = hashFunction(inputSearch);
        if(hashMap[hash_val]->value == inputSearch) {
            return 1;
        }
        else{
            item* myPtr = hashMap[hash_val];//Should be next cause I compare the first one already
            while(myPtr != nullptr){
                if(myPtr->value == inputSearch)
                {return 1;}
                myPtr = myPtr->next;
            }
        }
        return 0;
}
bool isString(std:: string x){
    int i;
    if(x.size() == 0)
        return 0;
    for( i = 0 ; i < x.size(); i++){
        if(i == x.size() - 1&& (x[i] =='.'||x[i] ==','))
            return 1;
        else if( i == x.size() - 2&& x[i] == 39 && (x[x.size() -1] =='s'||x[x.size() -1] =='d'))
            return 1;
        else if(tolower(x[i]) < 97 || tolower(x[i]) > 122){
            return false;
        }
    }
    if(x[i-1] == 46)
        return true;
    else if((tolower(x[i-1])>=97) && (tolower(x[i-1]) <=122))
        return true;
    return false;
}
void checkFileWord(std::ifstream &checkFile,hashTable myHash, int &wordInfile,int &count,int &missSpell){
    hashTable fileHash;
    string str, check;
    int size;
    while(getline(checkFile,str)){
        size = str.find(' ');
        while(size != - 1) {
            check = str.substr(0,size);
            str = str.substr(size+1);
            size = str.find(' ');
            if(str[0] != ' ')
                wordInfile++;
            if(isString(check)) {
                transform(check.begin(), check.end(), check.begin(), ::tolower);
                if(!myHash.search(check)){
                    missSpell++;
                }
                count++;
            }
        }
        wordInfile++;
        if(isString(str)) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if(!myHash.search(str)){
                missSpell++;
            }
            count++;
        }
    }
}