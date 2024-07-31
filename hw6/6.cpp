#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include "container_cout.h"

using std::cout, std::endl, std::vector, std::list, std::set;


template<typename T>
T maxElement(T it1, T it2)
{
    T mx = it1;

    for (T it = it1; it != it2; it++)
    {
        if (*it > *mx)
            mx = it;    
    }

    return mx;
}

int main()
{
    vector<int> v = {1, 3, 2, 7, 5, 2, 10};
    list<int> l = {1, 3, 2, 7, 5, 2, 10};
    set<int> s = {1, 3, 2, 7, 5, 2, 10};

    cout << *maxElement(v.begin(), v.end()) << endl;
    cout << *maxElement(l.begin(), l.end()) << endl;
    cout << *maxElement(s.begin(), s.end()) << endl;


    return 0;
}