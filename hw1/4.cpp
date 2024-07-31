#include <iostream>


void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther);
int strlen (const char* str);

int main()
{
	int numLetters = 0;
	int numDigits  = 0;
	int numOther   = 0;
	countLetters("MiPt1 !", numLetters, numDigits, numOther);
	std::cout << numLetters << " " << numDigits << " " << numOther << " " ;
	return 0;
}


int strlen (const char* str)
{
	char curr = ' ';
	int i = 0;
	while (curr != '\0')
	{
		curr = str[i];
		i++;
	}
	return i - 1;
}


void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther)
{
	int n = strlen(str);
	char curr = ' ';
	for (int i = 0; i < n; i++)
	{
		curr = str[i];
		if ((48 <= curr) && (curr <= 57))
			numDigits  += 1;
		else if ( ((65 <= curr) && (curr <= 90 )) || ((97 <= curr) && (curr <= 122)))
			numLetters += 1;
		else
			numOther   += 1;
	}
}


