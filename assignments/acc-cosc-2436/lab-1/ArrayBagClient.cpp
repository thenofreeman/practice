// TITLE        ACC COSC-2436 - Lab 1
// AUTHOR:      Nolan Freeman Abbott
// STATUS:      Complete
// DESCRIPTION: Provide a client interface to interact with an Bag class,
// ------------ that allows the user to perform operations such as:
// ------------ add, sort, search, and remove items, through an convienient
// ------------ text based, command line interface.

#include <climits> // INT_MAX
#include <iostream> // std::cout, std::cin
#include <string> // std::string

#include "ArrayBag.h" // ArrayBag<type>

void menuADD(ArrayBag<int>& bag);
void menuFIND(ArrayBag<int>& bag, const bool& recursively=false);
void menuSORT(ArrayBag<int>& bag);
int makeSelection(const int& low, const int& high);
void printList(const int* list, const int& size);
int promptOperation(const std::string& operation);

int main()
{
	ArrayBag<int> bag;
	// int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	int items[] {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39};
	// int initialValueCount{20};
	int initialValueCount{11};
		
	std::cout << "\nAdding positive integers to the bag:\n";
	for (int i{0}; i < 11; ++i)
		bag.add(items[i]);

	printList(items, initialValueCount);

	// hold the menu option the user will select
	int selection{0};
	// true when the user decides to quit
	bool isDone{false};
	//
	bool autoDisplayContents{true};

	do // while (!done)
	{
		std::cout << '\n'
				  << "Main Menu:\n"
				  << "(1) Print bag contents\n"
				  << "(2) Add a value to bag\n"
				  << "(3) Remove value from bag\n"
				  << "(4) Find value in bag (iteratively)\n"
				  << "(5) Find value in bag (recursively)\n"
				  << "(6) Sort bag\n"
				  << "(7) Quit\n"
				  << "Please make a selection: ";

		selection = makeSelection(1, 7);

		switch (selection)
		{
			case 1:
				// print bag contents
				std::cout << "\nPrinting bag contents:\n";
				// does nothing; contents are autodisplayed after
				// each valid selection (unless the user quits)
				break;
			case 2:
				// Add value to bag
				menuADD(bag);
				break;
			case 3:
				// Remove value from bag
				if (bag.remove(promptOperation("REMOVE")))
					std::cout << "Value removed.\n";
				else
					std::cout << "Value not in bag.\n";

				break;
			case 4:
				// Find value in bag iteratively
				menuFIND(bag, false); // false == !recursive
				break;
			case 5:
				// Find value in bag recursively
				menuFIND(bag, true); // true == recursive
				break;
			case 6:
				// Sort bag
				menuSORT(bag);
				break;
			case 7:
				// quit
				std::cout << "\nQuitting...\nGoodbye.\n";
				isDone = true;
				autoDisplayContents = false;
				break;
			case -1:
				// Selection was predicably invalid
				// [[fallthrough]]; // explicit fallthrough (C++17)
			default:
				// Selection was invalid
				std::cout << "\nInvalid selection.\n";
				autoDisplayContents = false;
				break;
		} // end if

		if (autoDisplayContents)
		{
			// convert the bag to a vector, which can be
			// used like a normal list since values are stored
			// contiguously in memory
			printList(&bag.toVector()[0], bag.getCurrentSize());
		} // end if

		// reset the value to true,
		// in the event of an invalid selection
		autoDisplayContents = true;

	} while (!isDone);

   return 0;
   
}  // end main

// -----------------------------------------------------------------------------
// Function: menuADD
// Inputs:   - an =ArrayBag= object of type =int=
//             that the user will append items to.
// Outputs:  - Text to the user describing the state of the bag.
//           - Values being appended to the =ArrayBag= object.
// Purpose:  Facilite adding values to the =ArrayBag= object by:
//           - Calling the function that prompts the user to insert a value.
//           - Displaying output to the user about the results of this action.
// -----------------------------------------------------------------------------
void menuADD(ArrayBag<int>& bag)
{
	int value{promptOperation("ADD")};

	std::cout << '\n';

	if (bag.contains(value))
	{
		std::cout << "Value already exists in bag.\n";
	}
	else
	{
		// if the bag was able to be added.
		if (bag.add(value))
			std::cout << "Value Added.\n";
		else
			std::cout << "Value not added. Bag is full.\n";
	} // end if
} // end menuADD

// -----------------------------------------------------------------------------
// Function: menuFIND
// Inputs:   - an =ArrayBag= object of type =int= that the user wants to sort.
//           - A boolean variable that determines the type of search:
//             + TRUE  : recursive,
//             + FALSE : iterative
// Outputs:  - Text to the user detailing whether the value exists
//             or not in the bag.
// Purpose:  Conditionally do a recursive search on the bag if it is sorted,
//           otherwise ask the user if they would like to do so now.
// -----------------------------------------------------------------------------
void menuFIND(ArrayBag<int>& bag, const bool& recursively)
{
	int valueToFind{};

	if (!bag.isSorted())
	{
		std::cout << "\nYou must sort the bag before searching it.\nDo this now?\n"
		          << "(1) Yes\n"
				  << "(2) No\n"
				  << "Selection: ";

		// 1 == yes; 2 == no
		if (makeSelection(1, 2) == 1)
			menuSORT(bag);
		else
			std::cout << "\nNot sorting. Returning to main menu...\n";
	} // end if

	if (bag.isSorted())
	{
		valueToFind = promptOperation("FIND");

		bool found{};

		// search methods return -1 is value not found
		// index returned from them, if not -1, is irrelevent for this assignment
		if (recursively)
			found = (bag.binarySearchRecursive(valueToFind) != -1);
		else
			found = (bag.binarySearchIterative(valueToFind) != -1);

		std::cout << "\nThe value " << valueToFind
				  << (found ? " is " : " is not ")
				  << "in the bag.\n";
	} // end if
} //end menuFIND

// -----------------------------------------------------------------------------
// Function: menuSORT
// Inputs:   - an =ArrayBag= object of type =int= that the user wants to sort.
// Outputs:  - Text to the user describing the state of the bag.
//           - A sorted =ArrayBag= object.
// Purpose:  Conditionally sorting the =ArrayBag= object if it wasn't already,
//           and Displaying output to the user about the results of this action.
// -----------------------------------------------------------------------------
void menuSORT(ArrayBag<int>& bag)
{
	// determine whether the bag was already sorted
	bool wasSorted{bag.isSorted()};

	if (!wasSorted)
	{
		std::cout << "\nSorting bag...\n";
		// sets bag::isBagSorted to true
	    bag.bubbleSort();
		std::cout << "Done. ";
	} // end if

	// let the user know if it was already sorted, or not
	std::cout << "Bag is" << (wasSorted ? " already " : " ") << "sorted.\n";
} // end menuSORT

// -----------------------------------------------------------------------------
// Function: makeSelection
// Inputs:   - A low and a high index, both of type =int=,
//             denoting the minimum and maximum accepted values.
//           - User input that will be checked to comply with the output format.
// Outputs:  - An integer from the user that satisfies the low-high constraints.
//           - =-1= if it is an integer, but not within range.
// Purpose:  Get user input until it is in form of a number,
//           returning it if it is in the range low-high, else -1.
// -----------------------------------------------------------------------------
int makeSelection(const int& low, const int& high)
{
	int selection{-1};

	// while input is not an integer
	// ie. cannot be pushed into the variable
	while (!(std::cin >> selection))
	{
		// clear fail bit && ignore extra characters
		// and newline left in input stream
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter a positive Integer: ";
	} // end while

	std::cin.ignore(1000, '\n');

	// verify the selection is within desired range
	if (!(selection >= low && selection <= high))
		selection = -1;

	return selection;
} // end makeSelection

// -----------------------------------------------------------------------------
// Function: printList
// Inputs:   - The list integers to be printed.
//           - The size of the list in parameter 1 (=int=).
// Outputs:  A formatted and printed list of all the values in said list.
// Purpose:  The function that is called whenever the user needs to have a list
//           of values printed in a formatted style.
// -----------------------------------------------------------------------------
void printList(const int* list, const int& size)
{
	std::cout << "{ ";

	for (int i{0}; i < size; ++i)
	{
		// print each value of the list conditionally
		// adding ", " if value is not the last value
		std::cout << list[i] << ( i < size-1 ? ", " : "");
	} // end for

	std::cout << " }\n";
} // end printList

// -----------------------------------------------------------------------------
// Function: promptOperation
// Inputs:   The =std::string= text describing the menu action.
// Outputs:  The output of the helper function =makeSelection()=.
// Purpose:  An intermediary function to prompt the user for input in the form
//           of any positive integer based on the supplied =operation= name.
// -----------------------------------------------------------------------------
int promptOperation(const std::string& operation)
{
	std::cout << "\nWhat value would you like to " << operation << "? ";

	// INT_MAX allows user to input any number
	// that a signed integer can hold
	// (determined by computers architecture)
	return makeSelection(1, INT_MAX);
} // end promptOperation
