#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome - Check whether int is palindrome or not
 * @n: unsigned int
 * Return: 1 if palindrome, 0 if not palindrome
*/
int is_palindrome(unsigned long n)
{
	unsigned long int beg, end, num;

	num = n;
	end = 10;
	beg = 1;

	while (num > 10)
	{
		num = num / 10;
		beg = beg * 10;
	}

	while (beg >= end)
	{
		if (n / beg % 10 != n % end)
			return (0);
		beg = beg / 10;
		n = n / 10;
	}
	return (1);
}
