#include "monty.h"
/**
 * execute - implement the opcode
 * @content: what is in the line
 * @stack: top of a linked list
 * @count: line count
 * @file: pointer to monty file
 * Return: Nothing
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opc)
	{
		if (strcmp(opc, opst[i].opcode) == 0)
		{
			opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (opc && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, opc);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
