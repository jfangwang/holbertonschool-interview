#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array: int array
 * @size: size_t
 * Return: void, prints out the avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (add_to_avl(array, size, 0, NULL));
}

avl_t *add_to_avl(int *array, size_t size, size_t index, avl_t *root)
{
	avl_t *new, *scout;

	if (!new)
		return (NULL);
	/* Base Case */
	if (index == size)
		return (root);

	/* Init new node */
	new = malloc(sizeof(avl_t));
	scout = malloc(sizeof(avl_t));
	if (!new || !scout)
		return (NULL);
	new->n = array[index];

	if (root == NULL)
	{
		/* This is the first node */
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;
	}
	else
	{
		scout = root;
		/* Traverse through the tree and find the leaf with no children */
		while (scout->left != NULL && scout->right != NULL)
		{
			if (new->n < scout->n)
				scout = scout->left;
			else
				scout = scout->right;
		}
		/* Add the new node to the tree */
		new->parent = scout;
		if (new->n < scout->n)
			scout->left = new;
		if (new->n < scout->n)
			scout->right = new;
	}

	/* check if tree is balanced */

	/* If false, balance the tree */

	add_to_avl(array, size, index + 1, root);
}
