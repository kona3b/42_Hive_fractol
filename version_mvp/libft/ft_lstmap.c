/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:47:11 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/08 14:22:02 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (0);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		if (!(new->next))
		{
			free(new);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (tmp);
}
