/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:46:50 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/11 22:15:20 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	error_and_free(t_node *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
}

void	free_args(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	print_stack(t_node *stack)
{
	t_node	*ptr;

	ptr = stack;
	while (ptr)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}

int	stack_size(t_node *stack)
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
