#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	/* Check if tree is NULL or has no right child */
	if (tree == NULL || tree->right == NULL)
		return (tree);
	/* Get the right child of the tree */
	new_root = tree->right;
	/* Move the left child of the new root to the right of the tree */
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;

	/* Update the parent pointers */
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (temp != NULL)
		temp->parent = tree;
	/* Return the new root */
	return (new_root);
}
