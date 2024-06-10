#include "binary_trees.h"

/**
 * array_to_bst_recursive - Builds a Binary Search Tree from an
 * array recursively.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Index of the start of the current subarray.
 * @end: Index of the end of the current subarray.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst_recursive(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;
	bst_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = array_to_bst_recursive(array, start, mid - 1);
	root->right = array_to_bst_recursive(array, mid + 1, end);

	return (root);
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (array_to_bst_recursive(array, 0, (int)size - 1));
}
