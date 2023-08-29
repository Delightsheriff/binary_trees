#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: The depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Initialize depth to zero */
	depth = 0;
	/* Traverse up the tree until reaching the root */
	while (tree->parent != NULL)
	{
		/* Increment depth by one */
		depth++;
		/* Move to the parent node */
		tree = tree->parent;
	}
	/* Return the depth */
	return (depth);
}
