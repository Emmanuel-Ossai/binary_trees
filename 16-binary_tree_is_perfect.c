#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree. If tree is NULL, return 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		return (left > right ? left : right);
	}
	else
		return (0);
}



/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 * Return: Size of the tree. If tree is NULL, return 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t n_left = binary_tree_size(tree->left);
	size_t n_right = binary_tree_size(tree->right);

	return (1 + n_left + n_right);
}



/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, perfect_size;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);
	perfect_size = (1 << (h + 1)) - 1;

	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
