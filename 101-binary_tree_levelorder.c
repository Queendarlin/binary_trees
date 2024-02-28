#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_levelorder_recursion(tree, func, 0,
			binary_tree_height(tree));
}

/**
 * binary_tree_levelorder_recursion - Recursively traverse the binary tree
 * and call the function to print nodes at each level.
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to a function to call for each node.
 * @level: The current level of the tree.
 * @height: The height of the tree.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder_recursion(const binary_tree_t *tree,
		void (*func)(int), size_t level, size_t height)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_levelorder_recursion(tree->left, func,
				level - 1, height);
		binary_tree_levelorder_recursion(tree->right, func,
				level - 1, height);
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_side, right_side;

	if (tree == NULL)
		return (0);

	left_side = binary_tree_height(tree->left);
	right_side = binary_tree_height(tree->right);

	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
}
