/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:31:20 by kaittola          #+#    #+#             */
/*   Updated: 2021/12/01 17:31:21 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*ret;

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
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
