#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (new_node == NULL)
			return (NULL);
		*tree = new_node;
		return (new_node);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if (balance_factor(*tree) > 1)
		{
			if (value < (*tree)->left->n)
				*tree = binary_tree_rotate_right(*tree);
			else
			{
				(*tree)->left = binary_tree_rotate_left((*tree)->left);
				*tree = binary_tree_rotate_right(*tree);
			}
		}
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if (balance_factor(*tree) < -1)
		{
			if (value > (*tree)->right->n)
				*tree = binary_tree_rotate_left(*tree);
			else
			{
				(*tree)->right = binary_tree_rotate_right((*tree)->right);
				*tree = binary_tree_rotate_left(*tree);
			}
		}
	}
	else
		return (NULL);
	return (*tree);
}
