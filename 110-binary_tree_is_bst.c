#include <limits.h>
#include "binary_trees.h"

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value allowed in the subtree
 * @max: The maximum value allowed in the subtree
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (1);
	/* Check if tree value is out of range */
	if (tree->n <= min || tree->n >= max)
		return (0);
	/* Recursively check the left and right subtrees */
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Check if the tree is a valid BST using range-based approach */
	return (is_bst(tree, INT_MIN, INT_MAX));
}
