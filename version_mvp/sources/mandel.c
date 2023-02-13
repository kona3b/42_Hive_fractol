/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:10:30 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/22 23:13:45 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_mandelbrot(t_mlx *mlx)
{
	double	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->y_pixel;
		mlx->y_pixel = 2 * mlx->x_pixel * mlx->y_pixel + mlx->constant_y;
		mlx->x_pixel = (mlx->x_pixel * mlx->x_pixel)
			- (tmp * tmp) + mlx->constant_x;
		if (((mlx->x_pixel * mlx->x_pixel)
				+ (mlx->y_pixel * mlx->y_pixel)) > 4)
			break ;
	}
}

void	mandelbrot_math(t_mlx mlx)
{
	mlx.y = 0;
	while (mlx.y < WIN_H)
	{
		mlx.x = 0;
		mlx.constant_y = mlx.y_axis_min
			+ (mlx.y + mlx.y_offset) * mlx.pixel_length_y;
		while (mlx.x < WIN_W)
		{
			mlx.constant_x = mlx.x_axis_min
				+ (mlx.x + mlx.x_offset) * mlx.pixel_length_x;
			mlx.x_pixel = mlx.constant_x;
			mlx.y_pixel = mlx.constant_y;
			mlx.color = 0;
			fractal_mandelbrot(&mlx);
			mlx_pixel_put(mlx.mlx, mlx.win,
				mlx.x, mlx.y, set_color(mlx.color));
			mlx.x++;
		}
		mlx.y++;
	}
	print_menu(&mlx);
}
