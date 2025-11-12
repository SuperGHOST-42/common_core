/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:47:06 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/12 00:08:04 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**get_args(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (&argv[1]);
}

int	free_args_and_exit(char **args, int argc)
{
	if (argc == 2)
		free_args(args);
	return (1);
}

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort_two(*a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(a, b);
	else
	{
		index_stack(*a, size);
		sort_radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		size;

	if (argc < 2)
		return (0);
	args = get_args(argc, argv);
	if (!args)
		return (1);
	stack_a = parse_and_init(args);
	if (!stack_a)
		return (free_args_and_exit(args, argc));
	stack_b = NULL;
	size = stack_size(stack_a);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b, size);
	if (argc == 2)
		free_args(args);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
