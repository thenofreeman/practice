#include <iostream>

int main()
{
    int numDoors{100};

    for (int i{1}; i*i <= numDoors; ++i)
        std::cout << "Door #" << i*i << " is Open\n";

    return 0;
}