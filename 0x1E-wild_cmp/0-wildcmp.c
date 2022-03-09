#include "holberton.h"


/**
 * wildcmp - Compares two strings with '*' wildcard
 * @s1: string 1
 * @s2: string 2
 * Return: 1 = strings are the same, 0 else.
 */
int wildcmp(char *s1, char *s2)
{
	char *a;
	char *b;

	a = s1;
	b = s2;

	if (*a == '\0' && *b == '*')
		return (wildcmp(a, b + 1));
	if (*a == '\0' && *b == '\0')
		return (1);
	if (*a == '\0' || *b == '\0')
		return (0);
	if (*a == *b)
		return (wildcmp(a + 1, b + 1));
	if (*b == '*')
	{
		if (*(b + 1) == '\0')
			return (1);
		if (*(a + 1) == *(b + 1))
			return wildcmp(a + 1, b + 1);
		if (*a == *(b + 1) || *(b + 1) == '*')
			return (wildcmp(a, b + 1) || wildcmp(a + 1, b));
		return (wildcmp(a + 1, b));
	}
	return (0);
}
