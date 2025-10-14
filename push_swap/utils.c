#include "pushswap.h"

int	is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int	i;
	int	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
            return (LONG_MAX);
	return (sign * result);
}

void free_stack(node *stack)
{
    node	*tmp;

	tmp = NULL;
    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}
void error_and_free(node *stack)
{
    write(2, "Error\n", 6);
    free_stack(stack);
}
int check_duplicate(node *stack, int value)
{
    while (stack)
    {
        if (stack->number == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
        free(split[i++]);
    free(split);
}

int	stack_size(node	*stack)
{
    int size;

	size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}
