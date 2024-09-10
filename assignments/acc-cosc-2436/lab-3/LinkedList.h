#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <string>
#include <vector>

#include "ListInterface.h"
#include "Node.h"

class LinkedList : ListInterface
{
    private:
        Node* headPtr;
        int numItems;

    public:
        LinkedList();
        virtual ~LinkedList();

        // add a new node to the list (maintaing sorted)
        bool addNode(const std::string& value);
        // convert list to an iterable vector for printing
        auto toVector() const -> std::vector<std::string>;
        // return count of items in the list
        int getNumItems() const;
};

#include "LinkedList.cpp"

#endif // LINKED_LIST_
