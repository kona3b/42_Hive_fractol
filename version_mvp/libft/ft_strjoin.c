/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:35:59 by kaittola          #+#    #+#             */
/*   Updated: 2021/11/25 13:36:53 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_len(const char *s)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_find_len(s1);
	len = len + ft_find_len(s2);
	str = (char *) malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
