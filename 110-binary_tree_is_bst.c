#include "binary_trees.h"

/**
 * find_node - Find a node in a tree.
 * @root: Root of the tree to evaluate.
 * @node: Node to find.
 * Return: 1 if node exists, 0 if not.
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{
	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

/**
 * traverse_tree - Traverse the tree checking if each node exists correctly.
 * @root: Root node of the tree.
 * @node: Current node to evaluate.
 *
 * Return: 1 if is BST, 0 if not.
 */
int traverse_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int is_bst = 0;

		is_bst = find_node(root, node);
		if (node->left)
			is_bst &= traverse_tree(root, node->left);
		if (node->right)
			is_bst &= traverse_tree(root, node->right);
		return (is_bst);
	}
	return (1);
}

/**
 * binary_tree_is_bst - Check if it's a correctly BST tree.
 * @tree: Tree to check.
 * Return: 1 if it's BST, 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (traverse_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}

