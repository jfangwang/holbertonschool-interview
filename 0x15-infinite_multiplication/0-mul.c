#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main - prdouct of 2 numbers
 * @a: argc
 * @b: argv
 * Return: 0 or 1
 */
int main(int a, char *b[])
{
	if (a == 3)
	{
		printf("%d\n", atoi(b[1]) * atoi(b[2]));
		return (0);
	}
	else
	{
		printf("Error\n");
		exit (98);
	}
}
