#include "LinkedList.h"

#include <iostream>
#include <string>
#include <vector>

LinkedList::LinkedList()
    : headPtr(nullptr), numItems(0)
{ }

LinkedList::~LinkedList()
{
    // while there are still nodes to delete
    while (headPtr != nullptr)
    {
        // current node to delete
        Node* del {headPtr};
        // next node to delete
        headPtr = headPtr->getNext();

        // cautiously set the deleted ptr's next to null
        // and delete it
        del->setNext(nullptr);
        delete del;
    }

    numItems = 0;
    headPtr = nullptr;
}

// addNode -> bool
//
// add a node to the linked list chain
// while maintaining a sorted state
// returns True when node was able to add
bool LinkedList::addNode(const std::string& valueToInsert)
{
    bool isDuplicate {false};

    // if the list is empty
    // create a new node at head
    if (numItems == 0)
    {
        headPtr = new Node(valueToInsert);
        numItems++;
    }
    else
    {
        Node* curr {headPtr};
        Node* prev {nullptr};

        // while not at end of chain
        // or insert index isn't found yet
        // continue iterating though nodes
        while (curr != nullptr && curr->getValue() <= valueToInsert)
        {
            prev = curr;
            curr = curr->getNext();
        }

        // found duplicate if the value at the insert index equals the value to add.
        if (prev != nullptr)
            isDuplicate = (prev->getValue() == valueToInsert);

        // if not a duplicate
        // insert a node at current interated 'index'
        if (!isDuplicate)
        {
            Node* newNode {new Node(valueToInsert)};

            if (prev == nullptr)
            {
                // at beginning of chain
                newNode->setNext(headPtr);
                headPtr = newNode;
            }
            else
            {
                // within chain or at end of chain
                prev->setNext(newNode);
                newNode->setNext(curr);
            }
            numItems++;
        }
    }

    // if value is not a duplicate,
    // it can be insertted
    return !isDuplicate;
}

// toVector -> vector<string>
//
// Iterate through the linkedlist nodes and convert
// them to a vector that can then be iterator over
// conveniently by the client program.
auto LinkedList::toVector() const -> std::vector<std::string>
{
    std::vector<std::string> oVect;

    Node* curr {headPtr};

    while (curr != nullptr)
    {
        oVect.push_back(curr->getValue());
        curr = curr->getNext();
    }

    return oVect;
}

// getNumItems -> int
//
// return the number of items in the linked list
int LinkedList::getNumItems() const
{
    return numItems;
}
