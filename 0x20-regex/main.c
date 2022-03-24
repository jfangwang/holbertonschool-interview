#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
	{\
		int res = regex_match(s, p);\
		printf("%s -> %s = %d\n", s, p, res);\
	}\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_MATCH("H", "*H");
	TEST_MATCH("ah", "asdf*.h");
	TEST_MATCH("H", ".");

	return (EXIT_SUCCESS);
}