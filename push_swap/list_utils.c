#include "pushswap.h"

void ft_lstadd_front(node **list, node *new)
{
	if (list == NULL || new == NULL)
		return ;
	new->next = *list;
	*list = new;
}

void ft_lstadd_back(node **list, node *new)
{
	node *ptr;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

node *ft_new_node(int value)
{
	node *node;

	node = malloc(sizeof(node));
	if (!node)
		return (NULL);
	node->number = value;
	node->next = NULL;
	return (node);
}

node 	*parse_and_init(char **str)
{
	int	i;
	long	num;
	node	*stack;
	node 	*new_node;

	stack = NULL;
	i = 0;
	while(str[i] != NULL)
	{
		if (!is_valid_number(str[i]))
			return (error_and_free(stack), NULL);
		num = ft_atol(str[i]);
		if (num == LONG_MAX || check_duplicate(stack, (int)num) || num == LONG_MIN)
			return (error_and_free(stack), NULL);
		new_node = ft_new_node((int)num);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

void print_stack(node *stack)
{
	node *ptr;

	ptr = stack;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}