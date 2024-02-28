#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (!tree)
		return (NULL);
	if (!*tree) /* If tree is empty, create a new node and set it as root */
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	current = *tree;
	while (current) /* Traverse tree to find right position to insert */
	{
		if (value < current->n)
		{
			if (!current->left)
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (!current->right)
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
		else
			return (NULL); /* Value already exists, do nothing */
	}
	return (NULL); /* Shouldn't reach here */
}
