#include <iostream>
#include <vector>
#include <span>
#include <utility>
#include "container_cout.h"
#include <cmath>

using std::vector, std::cout, std::pair, std::endl;


int div_amount(int n)
{
    if (n == 2)
        return 2;

    int res = 0;
    int isqrt = ceil(sqrt(n));
    for (int x = 1; x <= isqrt; x++)
    {
        if (n % x == 0)
            res += 1;
    }
    res *= 2;
    if (n % isqrt == 0)
        res -= 1;

    return res;
}

bool is_prime(int x)
{
    if (div_amount(x) == 2)
        return 1;
    else
        return 0;
}

vector< pair<int, int> > prime_divs(int n)
{
    if (is_prime(n))
        return {{n, 1}};

    static vector< pair<int, int> > res {{2, 0}};
    
    static int x = 2;

    if (!is_prime(x))
    {
        x += 1;
        return prime_divs(n);
    }

    if (n % x == 0)
    {
        if (res.back().first == x)
        {
            res.back().second += 1;
            if (x == ceil(n / x))
            {
                res.back().second += 1;
                return res;
            }
            return prime_divs(ceil(n / x));
        }
        else
        {
            
            res.push_back({x, 1});
            if (x == ceil(n / x))
            {
                res.back().second += 1;
                return res;
            }
            return prime_divs(ceil(n / x));
        }
    }
    else
    {
        x += 1;
        return prime_divs(n);
    }

}

int main()
{
    std::array<int, 3> arr = {256, 2, 107};
    vector< pair<int, int> > v;
    int isqrt = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << ":" << prime_divs(arr[i]) << std::endl;
    }
    
    return 0;
}
