#include "../includes/so_long.h"

int	ft_strlen_no_nl(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}