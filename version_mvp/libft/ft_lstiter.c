/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:46:59 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/07 13:47:08 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = lst;
	next = lst->next;
	while (current != NULL)
	{
		(*f)(current);
		if (next == NULL)
			break ;
		current = next;
		next = current->next;
	}
}
