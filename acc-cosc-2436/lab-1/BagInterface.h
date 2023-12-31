#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template <class ItemType>
class BagInterface
{
public:
	// -----------------------------------------------------------------------------
	// Function: bubbleSort
	// Inputs:   None
	// Outputs:  Nothing returned, but modifies the list contents of the bag.
	// Purpose:  Perform a bubble sort on the list values within the bag.
	// -----------------------------------------------------------------------------
	virtual void bubbleSort() = 0;

	// -----------------------------------------------------------------------------
	// Function: binarySearchIterative
	// Inputs:   A =value= to search for.
	// Outputs:  The index that the value was found at, else =-1=.
	// Purpose:  Iteratively do a binary search on the values stored in the Bag.
	// -----------------------------------------------------------------------------
	virtual int binarySearchIterative(const ItemType& value) const = 0;

	// -----------------------------------------------------------------------------
	// Function: binarySearchRecursive
	// Inputs:   A =value= to search for.
	// Outputs:  The output of binarySearchRecurisveHelper().
	// Purpose:  A function to abstract details away from the user,
	//           and calls its helper function to do the work.
	// -----------------------------------------------------------------------------
	virtual int binarySearchRecursive(const ItemType& value) const = 0;

	// -----------------------------------------------------------------------------
	// Function: binarySearchRecursiveHelper
	// Inputs:   - A =value= to search for.
	//           - integers denoting the left and right boundaries, and midpoint of
	//             the Bags list of values.
	// Outputs:  The index that the value was found at, else =-1=.
	// Purpose:  Recursively do a binary search on the values stored in the Bag.
	// -----------------------------------------------------------------------------
	virtual int binarySearchRecursiveHelper(const ItemType& value, int& leftBound, int& rightBound, int& midpoint) const = 0;

	// -----------------------------------------------------------------------------
	// Function: isSorted
	// Inputs:   None
	// Outputs:  Boolean; stating whether the bag is currently sorted or not.
	// Purpose:  An accessor method that only returns the variable of the Bag
	//           class that says whether it is sorted or not.
	// -----------------------------------------------------------------------------
	virtual bool isSorted() const = 0;

	// Gets the current number of entries in this bag.
	// Returns the integer number of entries currently in the bag
	virtual int getCurrentSize() const = 0;
   
	// Sees whether this bag is empty.
	// Returns True if the bag is empty, or false if not
	virtual bool isEmpty() const = 0;
   
	// Adds a new entry to this bag.
	// If successful, newEntry is stored in the bag and
	// the count of items in the bag has increased by 1.
	// Input: newEntry  The object to be added as a new entry.
	// Returns True if addition was successful, or false if not
	virtual bool add(const ItemType& newEntry) = 0;
   
	// Removes one occurrence of a given entry from this bag,
	// if possible.
	// If successful, anEntry has been removed from the bag
	// and the count of items in the bag has decreased by 1.
	// Input: anEntry  The entry to be removed.
	// Returns: True if removal was successful, or false if not
	virtual bool remove(const ItemType& anEntry) = 0;
   
	// Removes all entries from this bag.
	// Result: Bag contains no items, and the count of items is 0
	virtual void clear() = 0;
   
	// Counts the number of times a given entry appears in bag.
	// Input: anEntry  The entry to be counted
	// Returns: The number of times anEntry appears in the bag
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
   
	// Tests whether this bag contains a given entry.
	// Input: anEntry  The entry to locate
	// Returns: True if bag contains anEntry, or false otherwise
	virtual bool contains(const ItemType& anEntry) const = 0;
   
	// Empties and then fills a given vector with all entries that
	// are in this bag.
	// Returns: A vector containing all the entries in the bag
	virtual std::vector<ItemType> toVector() const = 0;
  
	// Destroys object and frees memory allocated by object.
	virtual ~BagInterface () { }
   
}; // end BagInterface
#endif // BAG_INTERFACE_
