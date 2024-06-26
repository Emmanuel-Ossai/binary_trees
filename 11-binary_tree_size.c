#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 * Return: Size of the tree. If tree is NULL, return 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_left, n_right;

	if (tree == NULL)
		return (0);

	n_left = binary_tree_size(tree->left);
	n_right = binary_tree_size(tree->right);

	return (1 + n_left + n_right);
}
