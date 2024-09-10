#include <iostream>
#include <cmath>

#include "NumberToWords.h"

int main()
{
    bool quit = false;
    long long input = -1;

    std::cout << "This program translates whole dollar amounts "
              << "into words for the for the purpose of writing checks." << '\n' << '\n'
              << "Entering a negaive terminates the program." << '\n';

    while(!quit){

        std::cout << "Enter an amount to be translated into words: ";

        if(!(cin >> input) || input < 0) {
            quit = true;
            std::cout << "Quitting..." << '\n';
        } else {
            Number num (input);
            std::cout << num;
        }
    }

    return 0;
}