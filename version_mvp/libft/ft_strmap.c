/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:31:16 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/01 17:31:17 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (!s || !f)
		return (0);
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	ret = (char *) malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
