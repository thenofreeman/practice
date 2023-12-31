#ifndef EMPLOYEE_INFO_H_
#define EMPLOYEE_INFO_H_

#include <string>

class EmployeeInfo
{
    private:
        int id;
        std::string name;

    public:
        EmployeeInfo(const int& id, const std::string& name);

        int getID();
        std::string getName();

        void setID(const int& id);
        void setName(const std::string& name);
        std::string toString();

};

#include "EmployeeInfo.cpp"

#endif // EMPLOYEE_INFO_H_
