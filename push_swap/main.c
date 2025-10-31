#include "pushswap.h"

int	main(int argc, char **argv)
{
	node	*stack_a;
	node	*stack_b;
	char	**args;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc < 2)
		return (0);
	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else if (argc > 2)
		args = &argv[1];
	stack_a = parse_and_init(args);
	if (!stack_a)
		return (1);
	size = stack_size(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size == 4 || size == 5)
			sort_five(&stack_a, &stack_b);
		else
		{
			index_stack(stack_a, size);
			sort_radix(&stack_a, &stack_b);
		}
	}
	if (argc == 2)
		free(args);
	return (0);
}
