#include <iostream>
#include <vector>
#include <algorithm>
#include "container_cout.h"


void solve(std::vector<int>& v)
{
    auto max_it = std::max_element(v.begin(), v.end());

    std::sort(v.begin(), max_it);
    std::sort(max_it, v.end(), [](int a, int b){return a > b;});
}


int main()
{
    std::vector<int> v = {3,1,4,9,6,4,10,10,3,7,6,2,4,3};

    solve(v);

    std::cout << v;

    return 0;
}