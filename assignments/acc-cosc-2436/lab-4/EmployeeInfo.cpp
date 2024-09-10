#include "EmployeeInfo.h"

#include <string>

EmployeeInfo::EmployeeInfo(const int& id, const std::string& name)
    : id(id), name(name)
{ }

int EmployeeInfo::getID()
{
    return id;
} // end getID

std::string EmployeeInfo::getName()
{
    return name;
} // end getName

void EmployeeInfo::setID(const int& id)
{
    this->id = id;
} // end setID
void EmployeeInfo::setName(const std::string& name)
{
    this->name = name;
} // end setName

// returns a string representation of the data stored in its node.
std::string EmployeeInfo::toString()
{
    return this->name + " [" + std::to_string(this->id) + "]";
} // end toString
