/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:10:13 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/11 21:42:37 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				number;
	struct s_node	*next;
}	t_node;

/* -------- parsing -------- */
int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_node *stack, int value);
t_node	*parse_and_init(char **str);

/* -------- linked lists -------- */
t_node	*ft_new_t_node(int value);
void	ft_lstadd_front(t_node **list, t_node *new);
void	ft_lstadd_back(t_node **list, t_node *new);
void	free_stack(t_node *stack);

/* -------- utils -------- */
void	error_and_free(t_node *stack);
void	print_stack(t_node *stack);
int		stack_size(t_node *stack);
void	free_args(char **ptr);

/* -------- moves -------- */
void	swap(t_node *a);
void	push(t_node **a, t_node **b);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* -------- sorting -------- */
int		is_sorted(t_node *a);
int		find_min(t_node *stack);
void	move_min_to_top(t_node **a, int value);
void	sort_two(t_node *a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
int		*stack_to_array(t_node *a, int size);
void	index_stack(t_node *a, int size);
void	sort_radix(t_node **a, t_node **b);

#endif
