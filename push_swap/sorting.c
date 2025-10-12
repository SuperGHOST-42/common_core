#include "pushswap.h"

int	is_sorted(node	*a)
{
	node	*tmp;

	if(!a)
		return (1);
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_two(node *a)
{
	if (a && a->next && a->number > a->next->number)
		sa(a);
}

void sort_three(node **a)
{
    int n1 = (*a)->number;
    int n2 = (*a)->next->number;
    int n3 = (*a)->next->next->number;

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
