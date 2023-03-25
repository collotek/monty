#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: head of the stack
 * @count: void
*/
void f_pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void) count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
