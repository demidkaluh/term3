#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <utility>
#include <cmath>

#include "container_cout.h"

using std::cout, std::endl, std::string, std::vector,
        std::string_view, std::array, std::pair;

template <typename T>
auto pairing(const T& C)
{
    using pairtype = std::pair<typename T::value_type, typename T::value_type>;
	using rtype = std::vector<pairtype>;


    pairtype p;
	rtype res;

    for (int i = 0; i < (std::ceil(C.size() / 2.)); i++)
    {
        res.push_back(p);        
    }

    for (int i = 0; i < C.size(); i++)
    {
        if (i % 2 == 0)
            res[i / 2].first = C[i];
        else
            res[i / 2].second = C[i];
    }

	return res;
}


int main()
{
    std::vector <int> v {10, 20, 30, 40, 50, 60};
    cout << pairing(v) << endl;
    

    std::array<std::string, 7> a {"cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf"};
    cout << pairing(a) << endl;


    std::string s {"Cats and dogs!"};
    cout << pairing(s) << endl;
}


/*
    Программа должна напечатать:

    [(10, 20), (30, 40), (50, 60)]
    [(cat, dog), (mouse, elephant), (tiget, axolotl), (wolf, )]
    [(C, a), (t, s), ( , a), (n, d), ( , d), (o, g), (s, !)]
*/