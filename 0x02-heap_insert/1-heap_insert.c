#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Max heap insert
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	heap_t *new, *node;

	new = binary_tree_node(*root, value);
	node = find_root(*root);
	new = insert_node(node, new);
	swap(new);
	return (new);
}

/**
 * swap - Will swap nodes to fix heap
 * @new_node: A double pointer to the root node of the Heap
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *swap(heap_t *new_node)
{
	int temp;

	if (new_node->parent == NULL)
		return (new_node);
	if (new_node->n > new_node->parent->n)
	{
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		return (swap(new_node->parent));
	}
	return (new_node);
}

/**
 * insert_node - Will insert a node in a balanced tree
 * @curr: A double pointer to the root node of the Heap
 * @new_node: The value to store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *insert_node(heap_t *curr, heap_t *new_node)
{
	if (curr->left == NULL && curr->right == NULL)
	{
		new_node->parent = curr;
		curr->left = new_node;
		return (new_node);
	}
	else if (curr->left && curr->right == NULL)
	{
		new_node->parent = curr;
		curr->right = new_node;
		return (new_node);
	}
	else if (curr->left->right == NULL || curr->left->right && curr->right->right)
	{
		return (insert_node(curr->left, new_node));
	}
	else
	{
		return (insert_node(curr->right, new_node));
	}
}

/**
 * find_root - Finds the root of the tree
 * @curr: A double pointer to the root node of the Heap
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *find_root(heap_t *curr)
{
	if (curr->parent == NULL)
		return (curr);
	return (find_root(curr->parent));
}
