//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file LinkedStack.h */

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"

template <class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
    private:
        Node<ItemType>* topPtr;

    public:
        LinkedStack();
        LinkedStack(const LinkedStack<ItemType>& aStack);
        virtual ~LinkedStack();

        bool isEmpty() const;
        bool push(const ItemType& newItem);
        bool pop();
        ItemType peek() const;

        LinkedStack<ItemType>& operator=(const LinkedStack<ItemType>& aStack);

}; // end LinkedStack

#include "LinkedStack.cpp"

#endif // LINKED_STACK_
