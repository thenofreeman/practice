#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 20; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];       // Array of bag items
	int itemCount;                          // Current count of bag items
	int maxItems;                           // Max capacity of the bag
	bool isBagSorted;                       // is the bag currently sorted
   
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();

	bool isSorted() const;
	int binarySearchIterative(const ItemType& value) const;
	int binarySearchRecursive(const ItemType& value) const;
	int binarySearchRecursiveHelper(const ItemType& value, int& leftBound, int& rightBound, int& midpoint) const;
	void bubbleSort();

	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	int getFrequencyOf(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif // ARRAY_BAG_
