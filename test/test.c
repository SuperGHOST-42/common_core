#include "libft.h"

#define BUFFER_SIZE 5
int	main(void)
{
	char	*buffer = malloc(BUFFER_SIZE + 1);
	int	fd = open("exemplo.txt", O_RDWR, O_APPEND);
	int	bytes;
	
	bytes = read(3, buffer, 5);
	write(3, "Olag", 4);

	perror("Write");

}