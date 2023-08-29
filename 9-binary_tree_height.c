#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Recursively measure the height of the left and right subtrees */
	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the maximum of the two heights plus one */
	return (l_height > r_height ? l_height : r_height);
}
