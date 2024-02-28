#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be
 * passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue to store the nodes */
	const binary_tree_t *queue[1000]; /* Assuming maximum of 1000 nodes */
	int front = 0, rear = 0;
	const binary_tree_t *current;

	/* Enqueue the root node */
	queue[rear++] = tree;

	/* Traverse the tree level by level */
	while (front < rear)
	{
		current = queue[front++];

		/* Print the value of the current node */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueue the right child if it exists */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
