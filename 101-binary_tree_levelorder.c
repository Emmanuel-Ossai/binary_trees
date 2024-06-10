#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the tree. If tree is NULL, return 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}



/**
 * print_at_level - Prints nodes at a specific level of the binary tree.
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to a function to call for each node.
 * @level: Level to print.
 */

void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_at_level(tree->left, func, level - 1);
		print_at_level(tree->right, func, level - 1);
	}
}



/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	size_t height = binary_tree_height(tree);
	size_t i;

	for (i = 1; i <= height; i++)
		print_at_level(tree, func, i);
}
