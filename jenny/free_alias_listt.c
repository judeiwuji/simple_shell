#include "shell.h"
/**

 * add_node_end - Adds a node to the end of a list_t linked list.

 * @head: A pointer to the head of the list_t list.

 * @dir: The directory path for the new node to contain.

 *

 * Return: If an error occurs - NULL.

 *         Otherwise - a pointer to the new node.

 */



list_t main(list_t **head, char *dir)
{

	list_t *new_node = malloc(sizeof(list_t));

	list_t *last;



	if (!new_node)

		return (NULL);



	new_node->dir = dir;

	new_node->next = NULL;



	if (*head)

	{

		last = *head;

		while (last->next != NULL)

			last = last->next;

		last->next = new_node;

	}

	else

		*head = new_node;



	return (new_node);

}



/**

 * free_alias_list - Frees a alias_t linked list.

 * @head: THe head of the alias_t list.

 */



void main(alias_t *head)
{

	alias_t *next;



	while (head)

	{

		next = head->next;

		free(head->name);

		free(head->value);

		free(head);

		head = next;

	}

}
