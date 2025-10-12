#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct node
{
	int             number;
	struct node    *next;
}   node;

/* -------- parsing -------- */
int     is_valid_number(char *str);
long    ft_atol(const char *str);
int     check_duplicate(node *stack, int value);
node    *parse_args(char **str);

/* -------- linked lists -------- */
node    *ft_new_node(int value);
void    ft_lstadd_front(node **list, node *new);
void    ft_lstadd_back(node **list, node *new);
void    free_stack(node *stack);

/* -------- utils -------- */
void    error_and_free(node *stack);
void    print_stack(node *stack);
int 	stack_size(node *stack);
int		find_min(node	*stack);

/* -------- moves -------- */
void	swap(node *a);
void	push(node **a, node **b);
void	rotate(node **stack);
void	reverse_rotate(node **stack);
void	sa(node *a);
void	sa(node *b);
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
int		is_sorted(node	*a);
void	sort_two(node *a);
void 	sort_three(node **a);

#endif
