#include "pushswap.h"

void	sa(node *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(node *b)
{
	swap(b);
	ft_printf("sb\n");
}

void ss(node *a, node *b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}

void	pa(node **a, node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(node **a, node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
void	ra(node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(node **a, node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rra(node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(node **a, node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}