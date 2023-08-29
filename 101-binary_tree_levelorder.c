#include <stdlib.h>
#include "binary_trees.h"

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
 * levelorder - Goes through a level of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * @level: The level to traverse
 */
void levelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	/* Check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Check if level is zero */
	if (level == 0)
	{
		/* Call the function with the node value */
		func(tree->n);
	}
	else
	{
		levelorder(tree->left, func, level - 1);
		levelorder(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	/* Check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Measure the height of the tree */
	height = binary_tree_height(tree);
	/* Loop through each level of the tree */
	for (i = 0; i < height; i++)
	{
		/* Traverse the current level */
		levelorder(tree, func, i);
	}
}
