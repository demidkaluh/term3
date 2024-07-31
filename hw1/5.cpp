#include <iostream>

struct Book
{
    char title[100];
    int pages;
    float price;
};

void addPrice (Book& book, float x);

int main()
{
	Book book = {"RT RT", 1, 5000};
	addPrice (book, 1000);
	std::cout<<book.price;
	return 0;
}


void addPrice (Book& book, float x)
{
	book.price += x;
}
