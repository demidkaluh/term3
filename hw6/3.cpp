#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>


bool is_all_upper(std::string_view sv)
{
    return std::all_of(sv.begin(), sv.end(), 
            [](char c){return std::isupper(c);});
}

int main()
{
    std::vector <std::string> v = {"MEOW", "meow", "Meow", "MEOW MEOW"};

    for (auto x : v)
    {
        std::cout << x << " " << is_all_upper(x) << std::endl;
    }
    

    return 0;
}