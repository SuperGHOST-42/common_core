#include "pushswap.h"

void	swap(node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
}

void	push(node **dest, node **src)
{
	node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	rotate(node **stack)
{
	node	*first;
	node	*new_first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	new_first = *stack;
	while (new_first->next)
		new_first = new_first->next;
	new_first->next = first;
}

void	reverse_rotate(node **stack)
{
	node	*prev;
	node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
