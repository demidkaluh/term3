#include <iostream>

int cubeR(const int& x);

int main()
{
	int x = 16;
	std::cout << cubeR(x); 
	return 0;
}


int cubeR(const int& x)
{
	return x * x * x;
}
