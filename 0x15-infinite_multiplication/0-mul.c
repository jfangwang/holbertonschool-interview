#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * _len - find the length of a string
 * @string: Given string
 * Return: The length of the string
 **/
int _len(char *string)
{
	char *start = string;

	while (*string)
	string++;
	return (string - start);
}

/**
 * _isdigit - check if string is digit or not
 * @num: input number as string
 * Return: 1 for true, 0 for false
 **/
int _isdigit(char *num)
{
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}
	return (1);
}

/**
 * main - prdouct of 2 numbers
 * @a: argc
 * @b: argv
 * Return: 0 or 1
 */
int main(int a, char *b[])
{
	if (a != 3 || _isdigit(b[1]) == 0 || _isdigit(b[2]) == 0)
	{
		printf("Error\n");
		exit(98);
	}
	printf("%d\n", atoi(b[1]) * atoi(b[2]));
	return (0);
}
