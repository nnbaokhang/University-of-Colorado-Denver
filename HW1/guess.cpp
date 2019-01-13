//
// Created by khang on 8/24/2018.
//

#include "guess.h"

void Guess::inputAnswer(Guess &guess,int n, int m){
    for(int i = 0 ; i < n ; i++){
        guess.answer.push_back((rand() % m) + 1); //Generate random number in the range between 1 and m
    }
}
void Guess::inputGuess(Guess &guess,int n,int m){

    int numb;
    cout<< "Enter your guess for the "<< n<<" integers in the range from 1 to "<<m <<"that have been selected: " << endl;
    for(int i = 0 ; i < n; i++){
        cin >> numb;
        guess.input.push_back(numb);
    }

}
int Guess::checkStatus(Guess guess){
    int count = 0;


        //find a(j) number of answer in guess. If found then assign to 0 and move to a(j+1).
        for( int i = 0 ; i < guess.answer.size(); i++){
            for( int j = 0; j < guess.input.size(); j++){
                if(guess.answer[i] == guess.input[j]) {
                    count++;
                    guess.input[j] = 0; // Assign a(j) == 0 outside the range between 1 and m.
                    break;
                }
            }
        }
    return count;
}
void Guess::printAnswer(Guess guess){
    for(int i = 0 ; i < guess.answer.size(); i++){
        cout<< guess.answer[i] <<" ";
    }
}
void Guess::clearAnswer(Guess &guess) {
    guess.answer.clear();
}

