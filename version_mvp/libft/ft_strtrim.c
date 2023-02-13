/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:22 by kaittola          #+#    #+#             */
/*   Updated: 2021/11/25 13:36:39 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_len(const char *s)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		i++;
		len++;
	}
	if (len == 0)
		return (len);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	len = ft_find_len(s);
	str = (char *) malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len-- > 0)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
