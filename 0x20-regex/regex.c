#include "regex.h"

/**
 * regex_match - finds the loop in a linked list
 * @str: String to scan
 * @pattern: Regular expression
 * Return: 1 if pattern matches, 0 on failure
 */
int regex_match(char *str, char *pattern)
{
	char *a;
	char *b;

	a = str;
	b = pattern;

	while (*(b + 1) != '\0')
		b++;
	while (*(a + 1) != '\0')
		a++;
	return (wildcmp(a, b));
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

	if ((*a == '\0' && *b == '\0') || *b == '*')
		return (1);
	if (*a == '\0' || *b == '\0')
		return (0);
	if (*a == *b || *b == '.')
		return (wildcmp(a - 1, b - 1));
	return (0);
}
