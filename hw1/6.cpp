#include <iostream>

struct Book
{
    char title[100];
    int pages;
    float price;
};


bool isExpensive (const Book& book);


int main()
{
	Book book1 = {"mipt mipt", 1, 1500};
	Book book2 = {"rt > fivt", 2, 700};
	std::cout << isExpensive(book1) << '\n';
	std::cout << isExpensive(book2);
	return 0;
}


bool isExpensive (const Book& book)
{
	return (book.price > 1000)? true : false;
}
