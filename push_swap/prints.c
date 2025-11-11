/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:47:13 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/11 21:09:42 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_node *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
