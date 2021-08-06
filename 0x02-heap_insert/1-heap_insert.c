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
		if (*root == NULL)
			return (NULL);
		return (*root);
	}

	new = binary_tree_node(*root, value);
	if (new == NULL)
		return (NULL);
	new = insert_node(*root, new);
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
	new_node->parent = curr;
	if (curr->left == NULL && curr->right == NULL)
		curr->left = new_node;
	else if (curr->left && curr->right == NULL)
		curr->right = new_node;
	else if (binary_tree_balance(curr->left) != 0 || binary_tree_balance(curr) < 0)
		return (insert_node(curr->left, new_node));
	else if (binary_tree_balance(curr->right) != 0 || binary_tree_balance(curr) > 0)
		return (insert_node(curr->right, new_node));
	else
		return (insert_node(curr->left, new_node));
	return (new_node);
}

/**
 * binary_tree_height - function
 * @tree: parent
 * Return: A pointer to the new node or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int right_sum = 0;
	int left_sum = 0;

	if (tree == NULL)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (tree->right)
		right_sum = 1 + binary_tree_height(tree->right);
	if (tree->left)
		left_sum = 1 + binary_tree_height(tree->left);
	if (left_sum > right_sum)
		return (left_sum);
	return (right_sum);
}
/**
 * binary_tree_balance - a
 * @tree: parent
 * Return: A pointer to the new node or NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

}

