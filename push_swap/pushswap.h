#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct node
{
	int			number;
	struct node	*next;
}	node;

/* -------- parsing -------- */
int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		check_duplicate(node *stack, int value);
node	*parse_and_init(char **str);

/* -------- linked lists -------- */
node	*ft_new_node(int value);
void	ft_lstadd_front(node **list, node *new);
void	ft_lstadd_back(node **list, node *new);
void	free_stack(node *stack);

/* -------- utils -------- */
void	error_and_free(node *stack);
void	print_stack(node *stack);
int		stack_size(node *stack);

/* -------- moves -------- */
void	swap(node *a);
void	push(node **a, node **b);
void	rotate(node **stack);
void	reverse_rotate(node **stack);
void	sa(node *a);
void	sb(node *b);
void	ss(node *a, node *b);
void	pa(node **a, node **b);
void	pb(node **a, node **b);
void	ra(node **a);
void	rb(node **b);
void	rr(node **a, node **b);
void	rra(node **a);
void	rrb(node **b);
void	rrr(node **a, node **b);

/* -------- sorting -------- */
int		is_sorted(node *a);
int		find_min(node *stack);
void	move_min_to_top(node **a, int value);
void	sort_two(node *a);
void	sort_three(node **a);
void	sort_five(node **a, node **b);
int		*stack_to_array(node *a, int size);
void	index_stack(node *a, int size);
void	sort_radix(node **a, node **b);

#endif
