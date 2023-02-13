/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:38:24 by kaittola          #+#    #+#             */
/*   Updated: 2021/11/25 13:37:22 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) malloc(size * sizeof(*ptr));
	if (!ptr)
		return (0);
	i = 0;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
