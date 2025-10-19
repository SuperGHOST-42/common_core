#include "pushswap.h"

int	is_sorted(node *a)
{
	if (!a)
		return (1);
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_two(node *a)
{
	if (a && a->next && a->number > a->next->number)
		sa(a);
}

void	sort_three(node **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->number;
	n2 = (*a)->next->number;
	n3 = (*a)->next->next->number;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(*a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(*a);
		rra(a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(*a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a);
}

int	find_min(node *stack)
{
	int	min;

	min = stack->number;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	return (min);
}

void	move_min_to_top(node **a, int min)
{
	node	*tmp;
	int		pos;
	int		size;

	if ((*a)->number == min)
		return ;
	else if ((*a)->next && (*a)->next->number == min)
	{
		sa(*a);
		return ;
	}
	tmp = *a;
	pos = 0;
	size = stack_size(*a);
	while (tmp && tmp->number != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while ((*a)->number != min)
			ra(a);
	else
		while ((*a)->number != min)
			rra(a);
}

void	sort_five(node **a, node **b)
{
	int	min;

	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		move_min_to_top(a, min);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

int	*stack_to_array(node *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (a)
	{
		arr[i++] = a->number;
		a = a->next;
	}
	return (arr);
}

void	index_stack(node *a, int size)
{
	int	*arr;
	int	i;
	int	j;
	int	rank;

	arr = stack_to_array(a, size);
	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (arr[i] > arr[j])
				rank++;
			j++;
		}
		a->number = rank;
		a = a->next;
		i++;
	}
	free(arr);
}

void	sort_radix(node **a, node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*a)->number >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
