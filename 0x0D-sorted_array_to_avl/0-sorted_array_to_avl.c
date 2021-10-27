#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array.
 * The strategey is to take advantage of the sorted array and get the
 * middle number. Then we make two sub arrays, [0 .. mid - 1] and
 * [mid + 1 .. size - 1]. The two sub array will be the left and right
 * children of any given node and let recursion build out the tree.
 * @array: int array
 * @size: size_t size
 * Return: Pointer of new node or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (build_avl_tree(array, NULL, 0, size - 1));
}

/**
 * build_avl_tree - Function that builds an AVL tree from an array
 * @array: int array
 * @root: root of AVL Tree
 * @start: size_t of starting index of array
 * @end: size_t of ending index of array
 *  Return: Pointer of new node or NULL on failure
 */
avl_t *build_avl_tree(int *array, avl_t *root, size_t start, size_t end)
{
	size_t middle;
	avl_t *new;

	/* If Start > End, the current index has no children */
	if (start > end)
		return (NULL);
	middle = (start + end) / 2;
	new = add_new_node(array, middle, root);
	/* Recurse the left and right paths of the current node */
	if (middle < end)
		new->right = build_avl_tree(array, new, middle + 1, end);
	if (middle > start)
		new->left = build_avl_tree(array, new, start, middle - 1);
	return (new);
}

/**
 * add_new_node - Function that builds an AVL tree from an array
 * @array: int array
 * @index: int index in array
 * @parent: Parent node of new node
 * Return: returns the newly added node or NULL if node failed to create
 */
avl_t *add_new_node(int *array, int index, avl_t *parent)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	/* Init node */
	new_node->n = array[index];
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
