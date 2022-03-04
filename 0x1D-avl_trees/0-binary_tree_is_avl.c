#include "binary_trees.h"


/**
 * binary_tree_is_avl - Sorts AVL Tree
 * @tree: root node
 * Return: node
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	left = check_height(tree->left);
	right = check_height(tree->right);

	if (abs(left - right) > 1)
		return (0);
	return (check_bst(tree, INT_MIN, INT_MAX));
}


/**
 * check_height - Checks the difference of a sub tree's height
 * @tree: root node
 * Return: the difference height of all sub trees
 */
int check_height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);
	left = check_height(tree->left) + 1;
	right = check_height(tree->right) + 1;
	return (left < right ? right : left);
}


/**
 * check_bst - Check if tree is BST
 * @tree: root node
 * @min: min value
 * @max: max value
 * Return: 1 = valid avl, 0 = not valid
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if ((tree->left && tree->left->n <= min) ||
		(tree->right && tree->right->n >= max))
		return (0);
	if (!check_bst(tree->left, min, tree->n) ||
		!check_bst(tree->right, tree->n, max))
		return (0);
	return (1);
}
