// PROGRAM DESCRIPTION
// Return the highest bid of an auction
// based on the user input of a filename
// that holds a corresponding item name
// and a series of bid amounts.

/** @file main.cpp */

#include <fstream>
#include <iostream>
#include <string>

#include "LinkedStack.h"

int main() {
    // define a new stack object.
    LinkedStack<int> stack;

    std::string filename;
    std::ifstream file;

    // prompt for a file name until a valid
    // one is found and able to be opened.
    bool validFile{false};
    while (!validFile)
    {
        std::cout << "Enter the name of an auction file: ";
        std::getline(std::cin, filename);

        // attempt to open the file: filename.
        file.open(filename);

        // verify if the file can be opened.
        // continue while if no, exit loop if yes.
        if (!file)
            std::cout << "Filename: \"" << filename << "\" doesn't exist, or is ill-formatted.\n";
        else
            validFile = true;
    } // end while

    // let the user know the file can, and is being opened.
    std::cout << "\nOpening file: \"" << filename << '"' << "\n\n";

    std::string auctionTitle{""};
    std::getline(file, auctionTitle);

    // direct each bid amount from the file into a bid
    // variable to potentially be added to  on the stack.
    int bid{0};
    while(file >> bid)
    {
        // if this is the first bid amount
        // OR the bid is greater than the
        // current top value of the stack
        if (stack.isEmpty() || bid > stack.peek())
        {
            // push the bid onto the stack
            stack.push(bid);
        } // end if

    } // end while

    // print the value of the last added entry, which will always be the largest.
    std::cout << auctionTitle << " sold for $" << stack.peek() << '\n';

    // clean up files
    file.close();

    return 0;
} // end main
