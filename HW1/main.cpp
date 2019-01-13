#include <iostream>
#include <vector>
#include <cstdlib>
#include "guess.h"

using namespace std; // Don't have to prepend std::

int main() {

    int m , n; // n is quantity of number and m is maximum value of each number
    string menu;

    Guess guess;
    // Loop game
    while(1) {
        cout << "Let computer choose n number:" << endl;
        cin >> n;
        cout << "Choose the range from 1 to m:" << endl;
        cin >> m;
        guess.inputAnswer(guess,n ,m);
        guess.inputGuess(guess , n, m);
        int life = 3;

        while (life--)  // Player has n times to play the game
        {
            int check = guess.checkStatus(guess);
            if (check == n) {
                cout << " You have guessed correctly" << endl;
                break;
            } else {
                    cout << check << " of your guess are correct. You have " << life  << " more life. Guess again" << endl;
                guess.input.clear(); // Clear all the element in vector but the allocation still the same.
            }

            if (life == 0) {
                cout << "Game Over" << endl;
                cout << "Correct numbers are: "<<endl;
                guess.printAnswer(guess);
                cout <<".Hope you luck next time."<<endl;
                break;
                }
            guess.inputGuess(guess, n, m);
        }

        cout<< " Do you want to play again. Yes or No:"<<endl;
        cin >> menu;
        if(menu == "No")
            break;
        guess.input.clear();
        guess.clearAnswer(guess);

    }
    cout << "You successfully log out the game. Have a nice day"<<endl;
    return 0;
}
