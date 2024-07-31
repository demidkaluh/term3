#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string_view>

using std::cout, std::endl, std::string, std::string_view;

const string digits = "0123456789";


bool isIdentifier(std::string_view s)
{
    return (digits.find(s.substr(0, 1)) == string::npos) and 
        std::all_of(s.begin(), s.end(), [](char c){return ((48 <= c and c <= 57) or (65 <= c and c <= 90) or (97 <= c and c <= 122) or (c == 95));});
}


int main()
{
    std::vector <string> v = {"a", "hello world", "1c", "meow-meow"};

    for (auto x : v)
    {
        cout << '"' << x << '"' << " " << isIdentifier(x) << endl;
    }

    return 0;
}