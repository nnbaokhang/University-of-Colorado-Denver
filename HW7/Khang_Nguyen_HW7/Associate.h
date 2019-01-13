//
// Created by kha!ng on 10/12/2018.
//

#ifndef HW7_GETDATAFROMFILE_H
#define HW7_GETDATAFROMFILE_H

#include "Teller.h"

bool readDataFromFile(std::vector<int>& Arrival, std::vector<int>& Transaction);
//Read data from file and assign its data to vector arrival and transaction
//Input is input.txt
// Data will be stored in vector Arrival and Transaction
// Output 1 if read file success else 0
void processData1(Teller& Line,const std::vector<int>& Arrival,const std::vector<int>& Transaction);
//Only allowed customer to go to only one Line
// vector Arrival will contain arrival time
// vector Transaction will contain transaction time
// This function will calculate departure time and store it in Line
void processData2(Teller& Line,const std::vector<int>& Arrival,const std::vector<int>& Transaction);
//Customer may go to Line A or Line B or Line C.
//Customer will go to the line which is the most optimization that defines by how many people in line
//and waitTime
// This function will calculate arrival time and departure time and store it in Line
int minQueue(std::queue<int> A, std::queue<int> B, std::queue<int> C,int w1, int w2,int w3);
//This function helps to let customer choose to go to line have the least customer
//A , B , C will be the Line
//w1 ,w2 ,w3 is wait time
// Return 1 for line A, 2 for Line B and 3 for Line C
#endif //HW7_GETDATAFROMFILE_H
