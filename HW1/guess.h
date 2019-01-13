//
// Created by khang on 8/24/2018.
//

#ifndef HW1_GUESSGAME_H
#define HW1_GUESSGAME_H
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;
// Create ADT class Guess contain variables and operations
class Guess {

private:
    vector<int> answer;

public:
    vector<int> input;
    void inputAnswer(Guess &,int n,int m); // Functions help to random numbers and contain it in answer
    void inputGuess(Guess &, int n, int m); // Functions help player choose numbers and contain it in input
    int checkStatus(Guess guess); // Check if guess correct else show number of guesss are correct
    void printAnswer(Guess guess); // Display correct answer
    void clearAnswer(Guess &); // Clear old elements in answer
};

#endif //HW1_GUESSGAME_H
