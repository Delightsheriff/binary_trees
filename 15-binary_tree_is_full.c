#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Base case: empty tree is full */
	if (tree == NULL)
		return (0);
	/* Check if node has zero or two children */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) &&
		 binary_tree_is_full(tree->right));
	/* Otherwise, tree is not full */
	return (0);
}
