#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *);
typedef struct binary_tree_s avl_t;
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *build_avl_tree(int *array, avl_t *root, size_t start, size_t end);
avl_t *add_new_node(int *array, int index, avl_t *parent);


#endif /* _BINARY_TREES_H_ */
