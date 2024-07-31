#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include "container_cout.h"

std::map<int, int> solve(const std::vector<int>& v)
{
	std::map<int, int> res;

	for (int x : v)
	{
		if (res.count(x))
			res[x] += 1;
		else
			res.insert(std::pair<int, int> (x, 1));
	}

	return res;
}


int main()
{
	std::vector<int> v = {5, 1, 5, 1, 1, 1, 2, 1, 5, 1};
	std::cout << solve(v);



	return 0;
}