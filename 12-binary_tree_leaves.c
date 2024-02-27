#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves in the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If tree is a leaf (both left and right are NULL), return 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count the leaves in the left and right subtrees */
	size_t leaves_left = binary_tree_leaves(tree->left);
	size_t leaves_right = binary_tree_leaves(tree->right);

	/* Return the sum of leaves in the left and right subtrees */
	return (leaves_left + leaves_right);
}
