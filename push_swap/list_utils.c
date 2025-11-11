/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:47:00 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/11 21:51:45 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_front(t_node **list, t_node *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	t_node	*ptr;

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

t_node	*ft_new_t_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = value;
	node->next = NULL;
	return (node);
}
