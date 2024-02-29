#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    /* Base case: an empty tree is considered a valid Max Binary Heap */
    if (tree == NULL)
        return (1);

    /* Check if the current node's value is greater than its children */
    if (tree->left && tree->left->n > tree->n)
        return (0);
    if (tree->right && tree->right->n > tree->n)
        return (0);

    /* Recursively check the left and right subtrees */
    if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
        return (0);

    /* The tree is a valid Max Binary Heap */
    return (1);
}
