/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:47:26 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/11 21:09:42 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_node *a)
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

void	sort_two(t_node *a)
{
	if (a && a->next && a->number > a->next->number)
		sa(a);
}

void	sort_three(t_node **a)
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

int	find_min(t_node *stack)
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

void	move_min_to_top(t_node **a, int min)
{
	t_node	*tmp;
	int		pos;
	int		size;

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
