#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	levelorder_queue_t *new_node = malloc(sizeof(levelorder_queue_t));

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}



/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	while (head)
	{
		levelorder_queue_t *tmp = head;

		head = head->next;
		free(tmp);
	}
}



/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to push.
 * @tail: A double pointer to the tail of the queue.
 * Description: Exits with a status code of 1 upon malloc failure.
 */

void push(binary_tree_t *node, levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node = create_node(node);

	if (!new_node)
	{
		free_queue(*tail);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}



/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	if (!head || !*head)
		return;

	levelorder_queue_t *tmp = (*head)->next;

	free(*head);
	*head = tmp;
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 * Description: Exits with a status code of 1 upon malloc failure.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		exit(1);

	while (head)
	{
		if (head->node->left)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, &tail);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
