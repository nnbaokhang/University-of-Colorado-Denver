//
// Created by khang on 10/12/2018.
//
#include <iostream>
#include <queue>
#include <fstream>
#include "Teller.h"
using namespace std;
bool readDataFromFile(vector<int>& Arrival, vector<int>& Transaction){
    //If read file success return 1 else return 0
    ifstream myFile ("input.txt");
    if(!myFile.is_open()){
        cout << "File is currently not open" << endl;
        return 0;
    }
    else{
        int arrivalTime;
        int transactTime;
        while(!myFile.eof()){
            myFile >> arrivalTime;
            myFile >> transactTime;
            Arrival.push_back(arrivalTime);
            Transaction.push_back(transactTime);
        }
    }
    return 1;
}
int minQueue(queue<int> A, queue<int> B, queue<int> C,int w1, int w2,int w3){
    if((A.size() == B.size()) && (B.size() == C.size())){
        if((w1 == w2 )&& (w2 == w3))
            return 1;
        else if ((w1 <= w2) && (w1 <= w3))
            return 1;
        else if((w2 <= w3) && (w2 <= w1))
            return 2;
        else if((w3 <= w1) && (w3 <= w2))
            return 3;
    }
    else if((A.size() <= B.size()) &&(A.size() <= C.size()))
        return 1;
    else if((B.size() <= A.size()) && (B.size() <= C.size()))
        return 2;
    else if((C.size() <= A.size()) && (C.size() <= B.size()))
        return 3;
    return 0;
}
int minDeparture(queue<int> A, queue<int> B, queue<int> C){
    if(A.empty() || B.empty() || C.empty())
        return -1;
    if(A.front() <= B.front() && A.front() <= C.front()){
        return A.front();
    }
    else if(B.front() <= A.front() && B.front() <= C.front()){
        return B.front();
    }
    else if(C.front() <= A.front() && C.front() <= B.front()){
        return C.front();
    }
    return 0;
}
int maxDeparture(queue<int> A, queue<int> B, queue<int> C){
    if(A.empty() || B.empty() || C.empty())
        return -1;
    if(A.front() >= B.front() && A.front() >= C.front()){
        return A.front();
    }
    else if(B.front() >= A.front() && B.front() >= C.front()){
        return B.front();
    }
    else if(C.front() >= A.front() && C.front() >= B.front()){
        return C.front();
    }
    return 0;
}
void processData1(Teller& Line,const std::vector<int>& Arrival,const std::vector<int>& Transaction) {

    int waitTime = 0;
    myNode data;
    int departure = 0;
    int i = 0;
    //Loop through the arrival time
    //Store the arrival time and arrival terminal
    //Calculate waitTime for each customer
    //Store waitTime
    //Calculate departure time
    //Store departure time and departure terminal
   for(  ;i < Arrival.size() ;i++){
     data.Terminal = "Arrive at A";
     data.Time = Arrival[i];
     Line.setResult(data);
     waitTime =  departure - Arrival[i];
     if(waitTime < 0)
         waitTime = 0;
     else
         Line.setTotalWaitTime(waitTime);
     departure = Arrival[i] + Transaction[i] + waitTime;
     data.Terminal = "Departure at A";
     data.Time = departure;
     Line.setResult(data);
   }
    Line.setTotalCustomer(i);
}
void processData2(Teller& Line,const std::vector<int>& Arrival,const std::vector<int>& Transaction){
    int arrival;
    int count = 0;
    int waitTime1 = 0;
    int waitTime2 = 0;
    int waitTime3 = 0;
    myNode data;
    queue<int> A, B, C;
    queue<int> DA, DB, DC;
    //Loop through the Arrival array
    //Assign each arrival at an optimal terminal A , B or C
    //Calculate departure time for each arrival
    //Store arrival time and departure time in Line
    for(int i = 0 ; i < Arrival.size() ; i++){
         count++;
        arrival = Arrival[i];
        int maxDepart = maxDeparture(DA,DB,DC);
        int minDepart = minDeparture(DA,DB,DC);
        //If customer arrival at time when everyone already leave
        // Clear all the the wait line and departure line
        if(arrival >= maxDepart  && maxDepart != -1){
            A.pop();
            DA.pop();
            B.pop();
            DB.pop();
            C.pop();
            DC.pop();
        }
        //If customer arrival at time when some people still in lines
        //Choose one of three line which line has minimal customer in line
        //If A is min then choose A arrival else choose B else choose C
        else if(arrival >= minDepart && minDepart != -1){
            if(minDepart == DA.front()){
                A.pop();
                DA.pop();
            }
            else if(minDepart == DB.front()){
                B.pop();
                DB.pop();
            }
            else if(minDepart == DC.front()){
                C.pop();
                DC.pop();
            }
        }

        //Choose a line which has smallest number of people
        //Choose min queue
        //Choose line A
        if(minQueue(A,B,C,waitTime1,waitTime2,waitTime3) == 1){
            A.push(arrival);
            if(!DA.empty())
            waitTime1 = DA.back() - arrival;
            if(waitTime1 <= 0)
                waitTime1 = 0;
            else
                Line.setTotalWaitTime(waitTime1);
            DA.push(arrival + Transaction[i] + waitTime1);
            data.Time = arrival;
            data.Terminal = "Arrival at A";
            Line.setResult(data);
            data.Time =  (arrival+ Transaction[i] + waitTime1);
            data.Terminal = "Departure at A";
            Line.setResult(data);
            continue;
        }
        //Choose line B
        else if(minQueue(A,B,C,waitTime1,waitTime2,waitTime3) == 2){
            B.push(arrival);
            if(!DB.empty())
                waitTime2 =DB.back() - arrival;
            if(waitTime2 <= 0)
                waitTime2 =0;
            else
                Line.setTotalWaitTime(waitTime2);
            DB.push(arrival + Transaction[i] + waitTime2);
            data.Time = arrival;
            data.Terminal = "Arrival at B";
            Line.setResult(data);
            data.Time = (arrival+ Transaction[i] + waitTime2);
            data.Terminal = "Departure at B";
            Line.setResult(data);
            continue;
        }
        //Choose line C
        else if(minQueue(A,B,C,waitTime1,waitTime2,waitTime3) == 3)
        {
            C.push(arrival);
            if(!DC.empty())
                waitTime3 = DC.back() - arrival;
            if(waitTime3 <= 0)
                waitTime3 = 0;
            else
                Line.setTotalWaitTime(waitTime3);
            DC.push(arrival + Transaction[i] + waitTime3);
            data.Time = arrival;
            data.Terminal = "Arrival at C";
            Line.setResult(data);
            data.Time = ( arrival+ Transaction[i] + waitTime3);
            data.Terminal = "Departure at C";
            Line.setResult(data);
            continue;
        }
    }
    Line.setTotalCustomer(count);
}