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

	if (*a == '\0' && *b == '*')
		return (regex_match(a, b + 1));
	if (*a == '\0' && *b == '\0')
		return (1);
	if (*a == '\0' || *b == '\0')
		return (0);
	if (*a == *b || *b == '.')
		return (regex_match(a + 1, b + 1));
	if (*b == '*')
	{
		if (*(b + 1) == '\0')
			return (1);
		if (*(a + 1) == *(b + 1))
			return (regex_match(a + 1, b + 1));
		if (*a == *(b + 1) || *(b + 1) == '*')
			return (regex_match(a, b + 1) || regex_match(a + 1, b));
		return (regex_match(a + 1, b));
	}
	return (regex_match(a, b + 1));
}
