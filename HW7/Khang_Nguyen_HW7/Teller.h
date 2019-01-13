//
// Created by khang on 10/12/2018.
//
#ifndef HW7_ONELINETELLER_H
#define HW7_ONELINETELLER_H
#include <queue>
#include<string>
struct myNode{
   int Time; // Arrival or Departure Time
   std::string Terminal; // Arrival or Departure
   bool operator<(const myNode& rhs) const //  Ascending Order
   {
       return Time > rhs.Time;
   }
};
class Teller{
private:
    std::priority_queue<myNode> myQueue; //Use to store arrival and departure
    int totalWaitTime =0 ;
    int totalCustomer = 0;
public:
    Teller(){};
    //Default Constructor
    void setTotalCustomer(int data);
    //This function to store total of customer
    // Input is Node data which contains Time and Terminal
    // Output none
    void setTotalWaitTime(int waitTime);
    //This function to store total wait time
    //Input is each customer wait time
    //Output none
    void setResult(myNode& data);
    //This function to store arrival , departure time
    //Input is Node data which contains Time and Terminal
    //Output none
    void showQ() const;
    //This function to output arrival and departure time in increasing order
    // Input none
    //Output none
    void clear();
    //This function to clear every single data in priority_queue myQueue
    //Input none
    //Output none
    ~Teller();
    //Destructor

};

#endif //HW7_ONELINETELLER_H
