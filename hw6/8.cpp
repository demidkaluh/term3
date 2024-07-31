#include <iostream>
#include <list>
#include <forward_list>
#include <vector>
#include <algorithm>
#include <set>

#include "container_cout.h"

using std::cout, std::endl, std::vector, std::list, std::forward_list, std::set;


struct Sum
{
    int operator()(const int& a, const int& b)
    {
        return a + b;
    }
};


template<typename T>
T bestNeighbours(T it1, T it2, auto comp)
{
    int len = 0;

    for (T it = it1; it != it2; it++)
    {
        len++;
    }

    T it1_next = it1;
    it1_next++;
    auto max = comp(*it1, *it1_next);

    T it_max = it1;
    T it = it1;
    for (int i = 0; i < len - 1; i++)
    {
        T it_next = it;
        it_next++;

        auto curr = comp(*it, *it_next);

        if (curr > max)
        {
            max = curr;
            it_max = it;
        } 

        it++;
    }

    return it_max;
}

int main()
{
    std::vector<int> v = {50, 10, 10, 20, 90, 30, 40, 60, 80, 20};

    std::cout << *bestNeighbours(v.begin(), v.end(), Sum()) << std::endl;
    std::cout << *bestNeighbours(v.begin(), v.end(), [](int a, int b){return std::abs(a - b);}) << std::endl;

    return 0;
}