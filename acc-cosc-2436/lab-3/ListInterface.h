#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

#include <string>
#include <vector>

#include "Node.h"

class ListInterface
{
    public:
        virtual ~ListInterface() { }

        virtual bool addNode(const std::string& value) = 0;
        virtual auto toVector() const -> std::vector<std::string> = 0;
        virtual int getNumItems() const = 0;
};

#endif // LIST_INTERFACE_
