#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Check if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value the tree can contain
 * @max: The maximum value the tree can contain
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int binary_tree_avl_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_avl_helper(tree->left, min, tree->n) &&
			binary_tree_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!binary_tree_avl_helper(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs((int)(left_height - right_height)) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
}
