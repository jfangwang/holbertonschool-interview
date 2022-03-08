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

	b = s2;
	for (a = s1; *a != '\0'; a++)
	{
		if (*b == '\0')
			break;
		if (*b == '*')
		{
			while (*b == '*' && *b != '\0')
				b++;
			if (*b == '\0')
				return (1);
			while (*a != '\0')
				a++;
			a--;
			while (*b != *a && *a != '\0')
				a--;
		}
		if (*b != *a)
			return (0);
		b++;
	}
	while (*b == '*')
		b++;
	if (*b == *a)
		return (1);
	return (0);
}
