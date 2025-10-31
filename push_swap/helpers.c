#include "pushswap.h"

void	free_stack(node *stack)
{
	node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	error_and_free(node *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
void	print_stack(node *stack)
{
	node	*ptr;

	ptr = stack;
	while (ptr)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}

int	stack_size(node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
