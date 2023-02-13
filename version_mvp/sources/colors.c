/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:45 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/22 21:59:56 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_color1(int c)
{
	if (c == 1)
		return (COLOR_A);
	if (c == 3)
		return (COLOR_B);
	if (c == 6)
		return (COLOR_C);
	if (c == 9)
		return (COLOR_D);
	if (c == 12)
		return (COLOR_E);
	if (c == 15)
		return (COLOR_F);
	if (c == 18)
		return (COLOR_G);
	if (c == 21)
		return (COLOR_H);
	if (c == 24)
		return (COLOR_I);
	if (c == 27)
		return (COLOR_J);
	return (0);
}

static int	set_color2(int c, int ret)
{
	if (c == 30)
		return (COLOR_K);
	if (c == 33)
		return (COLOR_L);
	if (c == 36)
		return (COLOR_M);
	if (c == 39)
		return (COLOR_N);
	if (c == 42)
		return (COLOR_O);
	if (c == 45)
		return (COLOR_P);
	if (c == 48)
		return (COLOR_Q);
	if (c == 51)
		return (COLOR_E);
	if (c == 54)
		return (COLOR_S);
	if (c == 57)
		return (COLOR_T);
	if (c == 60)
		return (COLOR_U);
	if (c == 63)
		return (COLOR_V);
	return (ret);
}

int	set_color(int c)
{
	int	ret;

	ret = 0;
	ret = set_color1(c);
	ret = set_color2(c, ret);
	if (c > 63)
		ret = BLACK;
	return (ret);
}
