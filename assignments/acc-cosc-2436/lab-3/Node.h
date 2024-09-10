#ifndef NODE_
#define NODE_

#include <string>

class Node
{
    private:
        std::string line;
        Node* next;

    public:
        // remove the default constructor
        Node() = delete;
        // next takes nullptr as a defualt parameter
        Node(std::string line, Node* next);

        // returns a ptr to the next node
        Node* getNext() const;
        // returns the value of this node
        std::string getValue() const;
        // set the pointer to the next node
        void setNext(Node* nextNode);

};

#include "Node.cpp"

#endif // NODE_
