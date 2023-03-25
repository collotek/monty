#include "monty.h"

/**
 * f_queue - show queue
 * @head: head of queue
 * @count: line count
 */
void f_queue(stack_t **head, unsigned int count)
{
	(void) head;
	(void) count;
	bus.lifi = 1;
}

/**
 * addqueue - add to the queue
 * @head: tope noe
 * @n: new integer
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
