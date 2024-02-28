#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_side, left_side;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_side = binary_tree_height(tree->left);
	right_side = binary_tree_height(tree->right);

	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
}

/**
 * _print_level - Function to print a binary tree level
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @level: The binary tree level to print.
 *
 */
void _print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	level -= 1;
	_print_level(tree->left, func, level);
	_print_level(tree->right, func, level);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level = 0, height = 0;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (; level <= height; ++level)
		_print_level(tree, func, level);
}
