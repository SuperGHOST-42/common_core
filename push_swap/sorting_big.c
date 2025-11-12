/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:47:24 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/12 00:07:22 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*parse_and_init(char **str)
{
	int		i;
	long	num;
	t_node	*stack;
	t_node	*new_t_node;

	stack = NULL;
	i = 0;
	while (str[i])
	{
		if (!is_valid_number(str[i]))
			return (error_and_free(stack), NULL);
		num = ft_atol(str[i]);
		if (num == LONG_MAX || num == LONG_MIN
			|| check_duplicate(stack, (int)num))
			return (error_and_free(stack), NULL);
		new_t_node = ft_new_t_node((int)num);
		if (!new_t_node)
			return (NULL);
		ft_lstadd_back(&stack, new_t_node);
		i++;
	}
	return (stack);
}

void	sort_five(t_node **a, t_node **b)
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

int	*stack_to_array(t_node *a, int size)
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

void	index_stack(t_node *a, int size)
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

void	sort_radix(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	num;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			num = (*a)->number;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
