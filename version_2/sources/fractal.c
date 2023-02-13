/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:40:31 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/07 23:36:11 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_math(t_mlx *mlx)
{
	double	tmp;
	int		factor;

	tmp = 0.0;
	factor = 2;
	if (mlx->f_type == 3)
		factor *= -1;
	if (mlx->f_type == 2)
	{
		mlx->constant_y_2 = (mlx->julia_y - WIN_H * 0.25) / (WIN_H * 0.25);
		mlx->constant_x_2 = (mlx->julia_x - WIN_W * 0.25) / (WIN_W * 0.25);
	}
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->y_pixel;
		mlx->y_pixel = factor * mlx->x_pixel * mlx->y_pixel + mlx->constant_y_2;
		mlx->x_pixel = (mlx->x_pixel * mlx->x_pixel)
			- (tmp * tmp) + mlx->constant_x_2;
		if (((mlx->x_pixel * mlx->x_pixel)
				+ (mlx->y_pixel * mlx->y_pixel)) > 4)
			break ;
	}
}

void	fractal(t_mlx *mlx)
{
	mlx->y = 0;
	while (mlx->y < WIN_H)
	{
		mlx->x = 0;
		mlx->constant_y = mlx->y_axis_min
			+ (mlx->y + mlx->y_offset) * mlx->pixel_length_y;
		while (mlx->x < WIN_W)
		{
			mlx->constant_x = mlx->x_axis_min
				+ (mlx->x + mlx->x_offset) * mlx->pixel_length_x;
			mlx->x_pixel = mlx->constant_x;
			mlx->y_pixel = mlx->constant_y;
			mlx->constant_x_2 = mlx->constant_x;
			mlx->constant_y_2 = mlx->constant_y;
			mlx->color = 0;
			fractal_math(mlx);
			my_mlx_pixel_put(&mlx->img,
				mlx->x, mlx->y, set_color(mlx->color));
			mlx->x++;
		}
		mlx->y++;
	}
}
