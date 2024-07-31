#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "container_cout.h"

void mega_reverse(std::vector <std::string>& v)
{
    for (auto& x : v)
    {
        std::reverse(x.begin(), x.end());
    }

    std::reverse(v.begin(), v.end());
}

int main()
{
    std::vector <std::string> v = {"dog", "cat", "parrot"};

    mega_reverse(v);

    std::cout << v;

    return 0;
}