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

void	ss(node *a, node *b)
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
