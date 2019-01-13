#include <iostream>
#include "Scores.h"
#include "functions.h"
#include "Bank.h"
using namespace std;
int main()
{

    int Grade1[3] = {9,9,10};
    int Grade2[3] = {8,9,8};
    Scores s1(Grade1[0],Grade1[1],Grade1[2]);
    Scores s2(Grade2[0],Grade2[1],Grade2[2]);
    cout <<"Student 1 average score: " << s1.averageScore() << endl;
    cout <<"Student 2 average score: " << s2.averageScore() << endl;

    return 0;
}
