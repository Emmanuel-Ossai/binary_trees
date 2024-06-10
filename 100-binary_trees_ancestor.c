#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 * Return: Depth of the node. If tree is NULL, return 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}



/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t height_f = 0, height_s = 0;
	const binary_tree_t *aux = NULL;

	height_f = binary_tree_depth(first);
	height_s = binary_tree_depth(second);

	if (height_f && height_s)
	{
		if (height_f > height_s)
		{
			aux = first;
			first = second;
			second = aux;
		}

		while (first != NULL)
		{
			aux = second;
			while (aux != NULL)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}

	return (NULL);
}
