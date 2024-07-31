#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "container_cout.h"

using std::cout, std::endl, std::vector, std::pair, std::string;

template <typename T>
T mmax(vector<T>& v)
{
	T mx = v[0];
	int sz = v.size();

	for (int i = 1; i < sz; i++)
		if (v[i] > mx)
			mx = v[i];

	return mx;
}

int main()
{
	vector<int> v1              = {2, 11, 5, 67, -3};
	vector<float> v2            = {-10, 52.34, -44.3123, 109.9, 110};
	vector<string> v3           = {"MEOW", "KOKOKO", "BEEEEEE", "MIPT"};
	vector< pair<int, int> > v4 = {{-1, 8}, {-2, 123}, {3, 4}, {3, 5}};
	cout << v1 << "MAX:" << mmax(v1) << endl;
	cout << v2 << "MAX:" << mmax(v2) << endl;
	cout << v3 << "MAX:" << mmax(v3) << endl;
	cout << v4 << "MAX:" << mmax(v4) << endl;


	return 0;
}
