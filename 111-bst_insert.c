#include "binary_trees.h"

/**
 * bst_insert_node - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert_node(bst_t **tree, int value)
{
	bst_t *aux = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	aux = *tree;
	if (value < aux->n)
	{
		if (aux->left == NULL)
		{
			aux->left = binary_tree_node(aux, value);
			return (aux->left);
		}
		return (bst_insert_node(&(aux->left), value));
	}
	if (value > aux->n)
	{
		if (aux->right == NULL)
		{
			aux->right = binary_tree_node(aux, value);
			return (aux->right);
		}
		return (bst_insert_node(&(aux->right), value));
	}
	return (NULL);
}
