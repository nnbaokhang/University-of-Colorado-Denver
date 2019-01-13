//
// Created by khang on 9/13/2018.
//

#include <iostream>
#include "MyVector.h"
using namespace HW4;
int main() {
    MyVector strPtr;
    int menu;
    while(1) {
        std::cout << "1.Add a number into strPTr:" << std::endl;
        std::cout << "2.Remove last number from strPTr:" << std::endl;
        std::cout << "3.Size of strPtr" << std::endl;
        std::cout << "4.Check if strPTr is empty:" << std::endl;
        std::cout << "5.Search a number in strPtr:" << std::endl;
        std::cout << "6.Operator[]" << std::endl;
        std::cout <<"7.Print out all elements that in pointer's container:" << std::endl;
        std::cout << "0.Exit" << std::endl;
        std::cin >> menu;
        switch(menu){

            case 1 : {
                int numb;
                std::cout << "Please input number you want to add:" << std::endl;
                std::cin >> numb;
                strPtr.push_back(numb);
                break;
            }
            case 2 : {
                std::cout << " You removed last element" << std::endl;
                strPtr.pop_back();
                break;
            }
            case 3: {
                std::cout << "Size is:" << strPtr.size() << std::endl;
                break;
            }
            case 4: {
                if (strPtr.empty())
                    std::cout << "Empty" << std::endl;
                else
                    std::cout << "Not Empty" << std::endl;

                break;
            }
            case 5: {
                if(strPtr.size() == 0){
                    std::cout << "Nothing to show" << std::endl;
                    break;
                }
                int num;
                std::cout << "Please enter number you want to search:" << std::endl;
                std::cin >> num;
                std::cout << "The number you searched has index of:" << strPtr.search(num) << std::endl;

                break;
            }
            case 6: {
                if(strPtr.size() == 0){
                    std::cout << "Nothing to show" << std::endl;
                    break;
                }
                int i;
                std::cout << "Please input index you want to see from 0 to " << strPtr.size() - 1<< std::endl;
                std::cin >> i;
                std::cout << strPtr[i] << std::endl;
                break;
            }
            case 7:{
                if(strPtr.size() == 0) {
                    std::cout << "Nothing to print" << std::endl;
                break;
                }
                for(int i = 0 ; i < strPtr.size();i++)
                std::cout << strPtr[i] << " ";
                std:: cout << std::endl;
                break;
            }
            default:
                break;
        }
        if(menu == 0 )
            break;
    }
   return 0;
}