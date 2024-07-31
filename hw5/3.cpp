#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <cassert>

#include "container_cout.h"

struct MaxLen
{
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
	{
		return a.second - a.first < b.second - b.first;
	}
};


struct Reversed
{
	bool operator()(const int& a, const int& b) const
	{
		return a > b;
	}
};


std::multiset<int, Reversed> solve(const int& n, const std::vector<int>& v);
std::pair<int, int> get_cut_segment(std::multiset< std::pair<int, int>, MaxLen >& rope,const int& x);


std::multiset<int, Reversed> solve(const int& n, const std::vector<int>& v)
{
	std::multiset<int, Reversed> res;
	std::multiset< std::pair<int, int>, MaxLen > rope = {{0, n}};
	for (int x : v)
	{
		std::pair<int, int> cut_segment = get_cut_segment(rope, x);

		std::pair<int,int> seg1 = {cut_segment.first, x};
		std::pair<int,int> seg2 = {x, cut_segment.second};

		auto result_1 = rope.insert(seg1);    	
    	auto result_2 = rope.insert(seg2);

		rope.erase(rope.find(cut_segment));

		int mxlen = rope.rbegin()->second - rope.rbegin()->first;
		res.insert(mxlen);
	}
	
	return res;
}


std::pair<int, int> get_cut_segment(std::multiset< std::pair<int, int>, MaxLen >& rope,const int& x)
{
	std::pair<int, int> cut_segment;

	for (std::pair<int, int> segment : rope)
	{
		if ((segment.first < x) and (segment.second > x))
		{
			cut_segment = segment;
			break;
		}
	}

	return cut_segment;
}


int main()
{
	int len = 20;
	std::vector<int> v = {8, 10, 15, 1, 7, 4, 11, 18};

	std::cout << solve(len, v);


	return 0;
}