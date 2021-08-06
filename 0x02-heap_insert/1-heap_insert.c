#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Max heap insert
 * @root: A double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *node;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = binary_tree_node(*root, value);
	if (new == NULL)
		return (NULL);
	node = find_root(*root);
	new = insert_node(node, new);
	return (swap(new));
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
	else if (curr->left->right == NULL || curr->right->right)
	{
		return (insert_node(curr->left, new_node));
	}
	else
	{
		return (insert_node(curr->right, new_node));
	}
	return (NULL);
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

/**
 * new_node - a
 * @parent: parent
 * @value: Value
 * Return: A pointer to the new node or NULL
 */

heap_t *new_node(heap_t *parent, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}