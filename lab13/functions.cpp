#include "functions.h"
void bubbleSort(vector<Bank> & acctVector)
{
    //Bubble Sort records by name
    int maxElement;
    int index;
    Bank tempBank3;

    for (maxElement = acctVector.size() - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (acctVector[index].getName() > acctVector[index + 1].getName())
            {
//swap the entire record (name, number, balance)
                tempBank3 = acctVector[index];
                acctVector[index] = acctVector[index + 1];
                acctVector[index + 1] = tempBank3;
            }//if
        }//for
    }//for
}

ostream& operator << (ostream &out, Bank &tempBank)
{
    out << tempBank.getName() << endl;
    out << tempBank.getNumber()<<endl;
    out << tempBank.getBalance()<<endl<<endl;
    return out;
}

