#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
    // outer loop counter denotes the rightmost index that is sorted
    for (int low{0}; low < itemCount-1; ++low)
    {
        // inner loop counter denotes the current
        // index to be check with its neighbor
        for (int cur{0}; cur < itemCount-low-1; ++cur)
        {
            // is the current index larger than its neighbor?
            if(items[cur] > items[cur+1])
            {
                // perform swap of values using a temporary variable
                // so to not lose the value of the current index
                int temp = items[cur];
                items[cur] = items[cur+1];
                items[cur+1] = temp;
            } // end if
        } // end for
    } // end for
    isBagSorted = true;
} // end bubbleSort

template<class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(const ItemType& value) const
{
    bool valueFound{false};       // loop exit condition variable

    int leftBound{0},             // value of leftmost bound
        rightBound{itemCount-1},  // value of rightmost bound
        midpoint{};               // the midpoint between two bounds

    do { // while: !found, and there are still values to search through
        // set midpoint to midpoint between two bounds
        midpoint = leftBound + (rightBound - leftBound) / 2;

        if (value == items[midpoint])
            // midpoint is the value to find
            valueFound = true;
        else if (value > items[midpoint])
            // value to find is right of midpoint
            leftBound = midpoint+1;
        else if (value < items[midpoint])
            // value to find is left of midpoint
            rightBound = midpoint-1;

    } while (!valueFound && (leftBound <= rightBound));

    // conditionally return -1 if value has not been found,
    // because there are no more values to search through
    return valueFound ? midpoint : -1;
} // end binarySearchIterative

template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(const ItemType& value) const
{
    int leftBound{0},             // value of leftmost bound
        rightBound{itemCount-1},  // value of rightmost bound
        midpoint{};               // midpoint between two bounds

    // call helper method to do all the dirty work
    // leaving user with a clean client interface
    return binarySearchRecursiveHelper(value, leftBound, rightBound, midpoint);
} // end binarySearchRecursive

template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursiveHelper(const ItemType& value, int& leftBound, int& rightBound, int& midpoint) const
{
    // set midpoint to midpoint between two bounds
    midpoint = leftBound + (rightBound - leftBound) / 2;

    // loop exit condition variable
    bool valueFound{false};

    // no more values to search through
    if (leftBound > rightBound)
    {
        midpoint = -1;
        // found as in it is found to not exist in the list
        valueFound = true;
    }
    // there are still values to search through
    else
    {
        if (value == items[midpoint])
            // midpoint is the value to find
            valueFound = true;
        else if (value > items[midpoint])
            // value to find is right of midpoint
            leftBound = midpoint+1;
        else if (value < items[midpoint])
            // value to find is left of midpoint
            rightBound = midpoint-1;
    } // end if

    // conditionally return the midpoint index if found (or not if -1)
    // or recursively run the binary search again with the updated bounds
    return valueFound ? midpoint
                      : binarySearchRecursiveHelper(value, leftBound, rightBound, midpoint);
} // end binarySearchRecursiveHelper

template<class ItemType>
bool ArrayBag<ItemType>::isSorted() const
{
    // return the ArrayBag variable storing the
    // status of the bags sorted-ness
    return this->isBagSorted;
} // end isSorted

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY), isBagSorted(false)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
        // added to simply client interface
        isBagSorted = false;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
        isBagSorted = false;
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

