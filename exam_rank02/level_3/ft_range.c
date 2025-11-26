# include <stdlib.h>

int *ft_range(int start, int end)
{
	int	*arr;
	int size;
	int step;
	int i;

	if (start <= end)
	{
		size = end - start + 1;
		step = 1;
	}
	else
	{
		size = start - end + 1;
		step = -1;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = start;
		start += step;
		i++;
	}
	return (arr);
}