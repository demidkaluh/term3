#include <iostream>
#include <list>
#include <forward_list>
#include <vector>
#include <algorithm>

#include "container_cout.h"


template<typename T>
void swapNeighbours(T it1, T it2)
{
    int len = 0;

    for (auto it = it1; it != it2; it++)
    {
        len++;
    }

    T it = it1;

    for (int i = 0; i < len / 2; i++)
    {
        T next = it;
        std::advance(next, 1);
        std::swap(*it, *next);

        if (i < len / 2 - 1)
            std::advance(it, 2);
    }
}

int main()
{
    std::vector<int> v1 = {10, 20, 30, 40, 50};
    std::vector<int> v2 = {10, 20, 30, 40, 50, 60};

    swapNeighbours(v1.begin(), v1.end());
    swapNeighbours(v2.begin(), v2.end());

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}