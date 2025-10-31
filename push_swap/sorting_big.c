#include "pushswap.h"

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
	if (!arr)
		return (NULL);
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
	if (!arr)
		return ;
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
			int	num = (*a)->number;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
