#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Recursively measure the size of the left and right subtrees */
	size = binary_tree_size(tree->left) + binary_tree_size(tree->right);
	/* Return the size plus one */
	return (size + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);
	/* Recursively measure the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	/* Return the maximum of the two heights plus one */
	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height, power;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Measure the size and height of the tree */
	size = binary_tree_size(tree);
	height = binary_tree_height(tree);
	/* Calculate 2^height - 1 */
	power = 1;
	while (height > 0)
	{
		power *= 2;
		height--;
	}
	power--;

	/* Compare the size and power */
	if (size == power)
		return (1);
	/* Tree is not perfect */
	return (0);
}
