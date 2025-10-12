#include "pushswap.h"

int	main(int argc, char **argv)
{
	node	*stack_a;
	node	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);
	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else if(argc > 2)
		args = &argv[1];
	stack_a = parse_args(args);
	if (!stack_a)
		return (1);
	if(!is_sorted(stack_a))
		sort_three(&stack_a);
	print_stack(stack_a);

	if (argc == 2)
		free(args);
	return (0);
}

