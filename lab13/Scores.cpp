//
// Created by khang on 11/19/2018.
//

#include "Scores.h"
Scores::Scores(int _Quiz1, int _Quiz2, int _Quiz3){
    Quiz1 = _Quiz1;
    Quiz2 = _Quiz2;
    Quiz3 = _Quiz3;
}
int Scores::getQuiz1(){ return Quiz1;};
int Scores::getQuiz2() {return Quiz2;};
int Scores::getQuiz3() {return Quiz3;};
void Scores::setQuiz(int _Quiz1, int _Quiz2, int _Quiz3){
    Quiz1 = _Quiz1;
    Quiz2 = _Quiz2;
    Quiz3 = _Quiz3;
}