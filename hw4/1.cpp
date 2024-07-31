#include <iostream>
#include <vector>

int sumEven(const std::vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i]% 2 == 0) sum += v[i];
    
    return sum;
}

int main()
{
    std::vector<int> v = {3, 4, 7, 2, 2, 11};
    std::cout << sumEven(v);

    return 0;
}