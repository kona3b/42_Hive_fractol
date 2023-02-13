/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:11:21 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/14 09:59:51 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	w;
	int		i;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			w++;
		if (s[i] == '\0' && s[i - 1] != c)
			w++;
	}
	return (w);
}

static char	*ft_build_string(int i, const char *s, char c)
{
	char	*str;
	size_t	len;
	int		j;

	len = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	str = (char *) malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	i = i - (int)len;
	while (s[i] != c && s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_freeall(size_t i, char **arr)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (0);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**arr;
	size_t	x;
	int		i;

	i = 0;
	x = 0;
	if (!s)
		return (0);
	arr = (char **) malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	while (ft_count_words(s, c) > x)
	{
		while (s[i] == c)
			i++;
		arr[x] = ft_build_string(i, s, c);
		if (!arr[x])
			return (ft_freeall(x, arr));
		x++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	arr[x] = 0;
	return (arr);
}
