#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		_binary_tree_delete(tree->left);
		_binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	heap_t *root;
	heap_t *node;

	int arr [20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	
	root = NULL;

	for (i=0; i<len; i++)
	{
		node = heap_insert(&root, arr[i]);
		printf("Inserted: %d\n", node->n);
		binary_tree_print(root);
	}

	node = heap_insert(&root, 50);
	printf("Inserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 10);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 7);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 3);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 4);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 49);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 20);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	_binary_tree_delete(root);
	return (0);
}