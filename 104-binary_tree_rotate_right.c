#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	/* Check if tree is NULL or has no left child */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Get the left child of the tree */
	new_root = tree->left;
	/* Move the right child of the new root to the left of the tree */
	temp = new_root->right;
	new_root->right = tree;
	tree->left = temp;

	/* Update the parent pointers */
	new_root->parent = tree->parent;
	tree->parent = new_root;
	if (temp != NULL)
		temp->parent = tree;
	/* Return the new root */
	return (new_root);
}
