/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:49:55 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/20 18:55:38 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_message(const char *msg, int v)
{
	ft_putstr(msg);
	exit(v);
}

int	exit_success(void)
{
	exit_message(EXIT_WINDOW, EXIT_SUCCESS);
	return (0);
}
