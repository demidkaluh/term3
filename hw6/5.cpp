#include <iostream>
#include <string>
#include <algorithm>

using namespace std::string_literals;

using std::cout, std::string, std::endl;

void spaces_to_end(string& s)
{
    std::stable_partition(s.begin(), s.end(), 
        [](char c) {return c != ' ';});
}

int main()
{
    string s1 = "cats and dogs";
    spaces_to_end(s1);
    cout << '"' << s1 << '"' << endl;

    string s2 = "cats and dogs !";
    spaces_to_end(s2);
    cout << '"' << s2 << '"' << endl;

    return 0;
}