#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <utility>

#include "container_cout.h"

using std::cout, std::endl, std::string, std::vector,
        std::string_view, std::array, std::pair;


template<typename T>
class Manager
{
private:
    T obj;


public:
    Manager() {obj();}

    void allocate()
    {

    }


    void construct(const T& obj)
    {

    }


    void destruct()
    {

    }


    void deallocate()
    {

    }


    T& get()
    {
        return &obj;
    }


};


int main()
{



    return 0;
}