#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	temp = first;
	while (temp)
	{
		if (binary_tree_is_descendant_of(second, temp))
			return ((binary_tree_t *)temp);
		temp = temp->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_descendant_of - Checks if a node is descendant of another.
 * @node: A pointer to the node to check if it's a descendant.
 * @ancestor: A pointer to the ancestor node.
 *
 * Return: 1 if node is a descendant of ancestor, 0 otherwise.
 */
int binary_tree_is_descendant_of(const binary_tree_t *node,
		const binary_tree_t *ancestor)
{
	while (node)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}
	return (0);
}
