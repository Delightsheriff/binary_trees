#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Check if node is NULL */
	if (node == NULL)
		return (0);

	/* Check if node has no parent */
	if (node->parent == NULL)
		return (1);
	/* Node is not a root */
	return (0);
}
