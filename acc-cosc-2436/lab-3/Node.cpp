#include "Node.h"

#include <string>

Node::Node(std::string line, Node* next=nullptr)
    : line(line), next(next)
{ }

// getValue -> Node
//
// get a ptr to the next node
Node* Node::getNext() const
{
    return next;
}

// getValue -> string
//
// get the data attribute of the current node
std::string Node::getValue() const
{
    return line;
}

// setNext -> void
//
// set the pointer to the next node
void Node::setNext(Node* nextNode)
{
    next = nextNode;
}
