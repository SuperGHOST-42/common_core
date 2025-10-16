#include "pushswap.h"

int	is_sorted(node	*a)
{
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

// encontra o valor mínimo da stack
int	find_min(node *stack)
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

// move um valor até ao topo (decide entre ra e rra)
void	move_min_to_top(node **a, int min)
{
	node	*tmp;
	int		pos;
	int		size;

	if ((*a)->number == min)
		return ;
	else if ((*a)->next && (*a)->next->number == min)
	{
		sa(*a);
		return ;
	}
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

// ordena 5 números
void	sort_five(node **a, node **b)
{
	int	min;

	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		move_min_to_top(a, min);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

int *stack_to_array(node *a, int size)
{
    int *arr = malloc(sizeof(int) * size);
    int i = 0;

    while (a)
    {
        arr[i++] = a->number;
        a = a->next;
    }
    return arr;
}

void index_stack(node *a, int size)
{
    int *arr = stack_to_array(a, size);
    int i, j, rank;

    // atribui índice para cada número
    for (i = 0; i < size; i++)
    {
        rank = 0;
        for (j = 0; j < size; j++)
            if (arr[i] > arr[j])
                rank++;
        a->number = rank;
        a = a->next;
    }
    free(arr);
}

void sort_radix(node **a, node **b)
{
    int size = stack_size(*a);
    int max_bits = 0;
    int i, j;

    // calcula quantos bits precisamos
    while ((size - 1) >> max_bits)
        max_bits++;

    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        while (j++ < size)
        {
            if (((*a)->number >> i) & 1)
                ra(a);       // bit = 1 → fica em A
            else
                pb(a, b);    // bit = 0 → vai para B
        }
        while (*b)
            pa(a, b);        // devolve tudo para A
    }
}
