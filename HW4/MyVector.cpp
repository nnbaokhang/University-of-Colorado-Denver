//
// Created by khang on 9/13/2018.
//

#include "MyVector.h"
using namespace HW4;

void MyVector::push_back(T value) {
    // Create new space memory allocation  which tempt point to block of memory with space vsize + 1
    T* tempt = new T[vsize + 1];
    // Copy every element of old block memory(vec point to) to new block memory(tempt point to) from 0 to vsize - 1
    for(int i = 0 ; i < vsize ; i++) {
        tempt[i] = vec[i];
    }
    // I can add value to tempt[vsize] now because tempt point to block memory has (vsize + 1) size
    tempt[vsize] = value;

    // Let vec point to the same address that tempt at
    vec = tempt;
    // vsize increment 1 because I add one more value to block of memory
    vsize++;
    // Clean temporary pointer
    tempt = nullptr;
    delete tempt;
}
void MyVector::pop_back() {
    //Check if block memory empty or not
    if(vsize == 0)
        return;
    // Create a new temporary tempt with size is vsize
    T* tempt = new T[vsize];
    //Copy every elements from old vec to tempt from 0 to vsize - 2 because I want to remove index vsize - 1
    for(int i = 0 ; i < vsize - 1; i++) {
        tempt[i] = vec[i];
    }
    // Point vec to the same address as tempt
    vec = tempt;
    // Remove one element -> decrease size by 1
    vsize--;
    //Clean temporary pointer
    tempt = nullptr;
    delete tempt;
}
T MyVector::operator[] (int index){
    // return value at index
return vec[index];
}
int MyVector::size(){
    // return current size
    return vsize;
}
// Check if empty or not
bool MyVector::empty(){
    //If empty
    if(vsize == 0 )
        return 1;
    // Not empty
    return 0;
}

int MyVector::search(T Value){
    for(int i = 0 ; i < vsize ; i++){
        if(vec[i] == Value)
            return i;
    }
    return -1;
}
//Default constructor
MyVector::MyVector(){};