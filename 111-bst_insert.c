#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
		return (NULL);
	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (*tree == NULL)
		return (*tree = new_node);

	current = *tree;
	while (current != NULL)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
				return (current->left = new_node, new_node->parent = current);
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
				return (current->right = new_node, new_node->parent = current);
			current = current->right;
		}
		else
		{
			return (free(new_node), NULL);
		}
	}
	return (NULL);
}
