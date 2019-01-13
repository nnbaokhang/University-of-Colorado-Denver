//
// Created by khang on 11/19/2018.
//

#ifndef LAB12A_SCORES_H
#define LAB12A_SCORES_H


class Scores {
private:
    int Quiz1, Quiz2, Quiz3;
public:
    Scores(int _Quiz1, int _Quiz2, int _Quiz3);
    int getQuiz1();
    int getQuiz2();
    int getQuiz3();
    void setQuiz(int _Quiz1, int _Quiz2, int _Quiz3);
    int averageScore(){
     return ( Quiz1 + Quiz2 + Quiz3 ) / 3;
    }
};


#endif //LAB12A_SCORES_H
