#include "libft/libft.h"

typedef struct node
{
	int	number;
	struct node *next;
}node;

int	main(void)
{
	
	node *list = malloc(sizeof(node));
	node *list2 = malloc(sizeof(node));


	list->number = 20;
	list->next = list2;


	list2->next = NULL;
	 
	return (0);
}