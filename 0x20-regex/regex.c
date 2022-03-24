#include "regex.h"

/**
 * regex_match - finds the loop in a linked list
 * @str: String to scan
 * @pattern: Regular expression
 * Return: 1 if pattern matches, 0 on failure
 */
int regex_match(char *str, char *pattern)
{
	int adv = 1;

	if (*pattern == 0)
		return (*str == 0);
	if (*pattern && *(pattern + 1) && *(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
		{
			return (1);
		}
		adv = 0;
	}
	if ((*str && *pattern == '.') || *str == *pattern)
	{
		return (regex_match(str + 1, pattern + adv));
	}
	return (0);
}


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

	printf("a: %s b: %s\n", a, b);

	if ((*a == '\0' && *b == '\0') || *b == '*')
		return (1);
	if (*a == '\0' || *b == '\0')
		return (0);
	if (*a == *b || *b == '.')
		return (wildcmp(a - 1, b - 1));
	return (0);
}
