#include <iostream>

int cubeV(int x);

int main()
{
	std::cout << cubeV(16); 
	return 0;
}


int cubeV(int x)
{
	return x * x * x;
}
