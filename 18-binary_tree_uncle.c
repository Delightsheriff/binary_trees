#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: Pointer to the sibling node, or NULL if none
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	/* Check if node or parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Get the parent node */
	parent = node->parent;

	/* Check if node is the left or right child of the parent */
	if (node == parent->left)
	{
		/* Return the right child of the parent */
		return (parent->right);
	}
	else
	{
		/* Return the left child of the parent */
		return (parent->left);
	}
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle node, or NULL if none
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node or parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Find the sibling of the parent node */
	return (binary_tree_sibling(node->parent));
}
