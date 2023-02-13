/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:17:20 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/08 13:54:26 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	j = 0;
	i = 0;
	size = ft_find_len(s1) + ft_find_len(s2);
	if (n == 0)
		return (ft_find_len(s2));
	while (s1[i] != '\0' && n > (i + 1))
		i++;
	if (s1[i] != '\0' && n == i + 1)
		return (n + ft_find_len(s2));
	while (s2[j] != '\0' && n > (i + 1))
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (size);
}
