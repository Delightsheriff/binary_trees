#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: The number of nodes, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Check if tree has at least one child */
	if (tree->left != NULL || tree->right != NULL)
	{
		/* Recursively count the nodes of the left and right subtrees*/
		nodes = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
		/* Return the number of nodes plus one */
		return (nodes + 1);
	}
	/* Tree has no children */
	return (0);
}
