#include <iostream>
#include <fstream>

#include "BinaryTree.h"
#include "EmployeeInfo.h"

void parseFileToTree(std::ifstream& file, BinaryTree<EmployeeInfo>& tree);

int main() {

    BinaryTree<EmployeeInfo> tree;

    std::cout << "\nBinary Tree Interface\n\n";

    std::ifstream file;      // file stream object to retrieve data
    std::string filename {}; // user inputted filename

    bool validFile {false};  // loop termination flag
    bool running {true};  // loop termination flag

    // continously prompt for a file name until a valid one presents
    while (running && !validFile)
    {
        // get user input of a name of the file
        std::cout << "Enter the name of a file to parse.\n"
                  << "\t[RETURN] for default.\n"
                  << "\t'q' to quit\n"
                  << "Filename: ";

        std::getline(std::cin, filename);

        // if user doesn't wish to quit
        if (filename != "q")
        {
            // if the user just hits return, use the default filename
            if (filename == "")
            {
                filename = "employeedata.txt";
                std::cout << "\nUsing default filename '" << filename << "'\n";

            }
            // attempt to open the file
            file.open(filename);

            // if the file cannot be opened
            if (!file)
                std::cout << "File: \"" << filename << "\" could not be found." << "\n" << '\n';
            else
                validFile = true;
        }
        else
        {
            // q was pressed
            std::cout << "Quitting...";
            running = false;
        }
    }

    // if q wasn't pressed in file stage
    if (running)
    {
        // parse the file
        parseFileToTree(file, tree);

        char choice {0}; // actual choice
        std::string userInput {0}; // whole input line

        while (running) {
            std::cout << "\nMain Options:\n"
                      << "\t(1) Find and Employee\n"
                      << "\t(2) Display Tree\n"
                      << "\t(3) Add an Employee\n"
                      << "\t(4) Quit\n"
                      << "Please make a selection: ";

            // get user input and extract only the first character
            std::getline(std::cin, userInput);
            choice = userInput[0];

            // { } inside case statements are used to avoid crossing initialization
            switch (choice)
            {
                case '1': // Find Employee
                {
                    std::string query {};
                    int queryAsInt {0};

                    std::cout << "\nEnter an ID to find: ";
                    std::getline(std::cin, query);

                    // attempt to convert query to an integer
                    // if not, tell user their input was bad
                    try {
                        queryAsInt = std::stoi(query);
                        std::cout << "\nEmployee '" << queryAsInt
                                  << "'" << (tree.exists(queryAsInt) ? " exists\n" : " doesn't exist.\n");
                    } catch (const std::invalid_argument& e) {
                        std::cout << "\nNot a valid ID.\n";
                    }
                }
                    break;
                case '2': // Display Tree
                    std::cout << '\n' << tree.displayTree() << '\n';
                    break;
                case '3': // Add Employee
                {
                    std::string newEmployeeID {};
                    std::string newEmployeeName {};

                    // get user desired input for new employee
                    std::cout << "\nEmployee ID: ";
                    std::getline(std::cin, newEmployeeID);
                    std::cout << "Full employee name: ";
                    std::getline(std::cin, newEmployeeName);

                    // attempt to convert employee id input to an integer
                    // if not, tell user their input was bad
                    try {
                        EmployeeInfo newEmployee (std::stoi(newEmployeeID), newEmployeeName);
                        if (tree.add(newEmployee))
                            std::cout << "\nAdded employee '" << newEmployeeName << "'\n";
                        else
                            std::cout << "\nEmployee with ID '" << newEmployeeID << "' already exists.\n";
                    } catch (const std::invalid_argument& e) {
                        std::cout << "\nNot a valid ID.\n";
                    }
                }
                    break;
                case '4': // Quit
                    running = false;
                    std::cout << "Quitting...";
                    break;
                default: // weird input, try again
                    std::cout << "\nSelection not valid.\n";
                    break;
            }
        }
    }

    return 0;
}

// ParseFileToTree
// takes a file object and a tree adt as input,
// parses the file containing key-value pairs and stores them into the tree adt
void parseFileToTree(std::ifstream& file, BinaryTree<EmployeeInfo>& tree)
{
    // variables to hold each chunks of the file input
    // 1234 Some name
    // does not verify that 1234 is actually an integer.. could potentially throw error
    std::string line[2] {"", ""};

    // while getline still can read a line
    while (std::getline(file, line[0], ' '))
    {
        std::getline(file, line[1]);

        // append value to tree
        tree.add(EmployeeInfo(std::stoi(line[0]), line[1])); // doesn't verify that line[0] is an int
    }
}
