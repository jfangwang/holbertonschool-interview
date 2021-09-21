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
	unsigned long beg, end, num;

	num = n;
	end = 10;
	beg = 1;

	if (n < 10)
		return (1);

	while (num > 10)
	{
		num /= 10;
		beg *= 10;
	}

	while (beg >= end)
	{
		printf("%lu, %lu, %lu, %lu\n", beg, end, n, (n / beg % 10));
		if (n / beg % 10 != n % end)
			return (0);

		n = n - beg * (n / beg % 10);
		beg /= 100;
		n /= 10;
	}
	return (1);
}
