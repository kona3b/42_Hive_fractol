/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:31:44 by kaittola          #+#    #+#             */
/*   Updated: 2022/01/24 13:47:19 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_if_overlong(int m)
{
	if (m == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int					m;
	unsigned long long	res;
	int					i;

	m = 1;
	res = 0;
	i = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		m = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (unsigned long long)*str - '0';
		str++;
		i++;
	}
	if (i > 19 || res > 9223372036854775807)
		return (ft_if_overlong(m));
	return ((int)res * m);
}
