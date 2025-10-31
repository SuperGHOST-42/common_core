#include "pushswap.h"

void	ft_lstadd_front(node **list, node *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

void	ft_lstadd_back(node **list, node *new)
{
	node	*ptr;

	if (!list || !new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

node	*ft_new_node(int value)
{
	node	*node;

	node = malloc(sizeof(node));
	if (!node)
		return (NULL);
	node->number = value;
	node->next = NULL;
	return (node);
}

node	*parse_and_init(char **str)
{
	int		i;
	long	num;
	node	*stack;
	node	*new_node;

	stack = NULL;
	i = 0;
	while (str[i])
	{
		if (!is_valid_number(str[i]))
			return (error_and_free(stack), NULL);
		num = ft_atol(str[i]);
		if (num == LONG_MAX || num == LONG_MIN || check_duplicate(stack, (int)num))
			return (error_and_free(stack), NULL);
		new_node = ft_new_node((int)num);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
