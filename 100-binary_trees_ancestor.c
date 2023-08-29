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

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	/* Check if first or second is NULL */
	if (first == NULL || second == NULL)
		return (NULL);
	/* Measure the depth of the first and second nodes */
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	/* Move up the deeper node until reaching the same level as the other node */
	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}
	/* Traverse up both nodes to find a common ancestor/reaching the root*/
	while (first != second && first != NULL && second != NULL)
	{
		first = first->parent;
		second = second->parent;
	}
	/* Return the common ancestor or NULL if none */
	return ((binary_tree_t *)first);
}
