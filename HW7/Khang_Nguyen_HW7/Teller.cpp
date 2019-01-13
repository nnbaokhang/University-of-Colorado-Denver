//
// Created by khang on 10/12/2018.
//

#include "Teller.h"
#include <iostream>
#include <string>
using namespace std;

void Teller::showQ() const
{
    std::priority_queue<myNode> g = myQueue;
    while (!g.empty())
    {
        cout << "Customer " << g.top().Terminal <<'\t' << "at the time: " << g.top().Time<< endl;
        g.pop();
    }
    cout << endl;
    cout <<"Final Statistics: " << endl;
    cout <<"Total number of people processed: " << totalCustomer << endl;
    cout <<"Average amount of time spent waiting: " << float(totalWaitTime) / 10;
    cout << '\n';
}
void Teller::setResult(myNode& data){
    myQueue.push(data);
}
void Teller::clear(){
    while(!myQueue.empty()){
        myQueue.pop();
    }
    totalWaitTime = 0;
    totalCustomer = 0;
}
void Teller::setTotalWaitTime(int waitTime) {
    totalWaitTime += waitTime;
}

Teller::~Teller() {
    clear();
}

void Teller::setTotalCustomer(int data){
    totalCustomer = data;
}