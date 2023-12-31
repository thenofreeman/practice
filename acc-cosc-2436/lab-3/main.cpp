// ACC-COSC-2436 Lab 3 - Linked Lists
// Author: Nolan Freeman Abbbott

// PROGRAM DESCRIPTION:
// --- Parse through a user specified file
// --- displays the number of lines found, number
// --- of unique lines found, and reorders them into
// --- a sorted list, using a linked list ADT.

#include <fstream> // ifstream | EOF
#include <iostream> // getline() | cout
#include <string> // string
#include <vector> // vector<T>

#include "LinkedList.h" // LinkedList<T>

int main() {

    std::ifstream file;      // file stream object to retrieve data
    std::string filename {}; // user inputted filename

    bool validFile {false};  // loop termination flag

    // continously prompt for a file name until a valid one presents
    while (!validFile)
    {
        // get user input of a name of the file
        std::cout << "Enter the name of a file to parse: ";
        std::getline(std::cin, filename);

        // attempt to open the file
        file.open(filename);

        // if the file cannot be opened
        if (!file)
            std::cout << "File: \"" << filename << "\" could not be found." << "\n" << '\n';
        else
            validFile = true;

        // TODO user wants to quit
    }

    // List ADT to hold input values
    LinkedList list;

    // --------------------------
    // begin reading file values
    // --------------------------

    std::string line {}; // intermediary input values
    int lineCount {0};   // number of lines read from input

    // while getline still can read a line
    while (std::getline(file, line))
    {
        // append value to list
        list.addNode(line);
        // increment number of lines read
        lineCount++;
    }

    // show how many lines were found in the file
    std::cout << "\nParsed file \"" << filename
              << "\" containing " << lineCount << " lines." << '\n' << '\n';

    // ----------------------
    // begin displaying data
    // ----------------------

    // convert the values in the list to a iterable vector
    std::vector<std::string> vList = list.toVector();

    // loop through each value in the vector
    // assigning its data to the variable "node"
    for (auto node : vList)
    {
        // print the value of the next element
        std::cout << node << '\n';
    }

    // show how many nodes were found in the list,
    // compared to how many were initially read in
    std::cout << '\n' << list.getNumItems() << " unique nodes printed from "
              << lineCount << " lines of input.";

    // clean up file object
    file.close();

    return 0;
}
