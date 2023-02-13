/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:51:02 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/23 20:23:10 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_julia(t_mlx *mlx)
{
	double	tmp;

	tmp = 0.0;
	while (mlx->color++ < mlx->iterations)
	{
		tmp = mlx->y_pixel;
		mlx->y_pixel = 2 * mlx->x_pixel * mlx->y_pixel + mlx->constant_y_julia;
		mlx->x_pixel = (mlx->x_pixel * mlx->x_pixel)
			- (tmp * tmp) + mlx->constant_x_julia;
		if (((mlx->x_pixel * mlx->x_pixel)
				+ (mlx->y_pixel * mlx->y_pixel)) > 4)
			break ;
	}
}

static void	julia_math(t_mlx *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	while (mlx->y < WIN_H)
	{
		mlx->x = 0;
		mlx->constant_y = mlx->y_axis_min + mlx->y * mlx->pixel_length_y;
		while (mlx->x < WIN_W)
		{
			mlx->constant_x = mlx->x_axis_min + mlx->x * mlx->pixel_length_x;
			mlx->x_pixel = mlx->constant_x;
			mlx->y_pixel = mlx->constant_y;
			mlx->color = 0;
			fractal_julia(mlx);
			mlx_pixel_put(mlx->mlx, mlx->win,
				mlx->x, mlx->y, set_color(mlx->color));
			mlx->x++;
		}
		mlx->y++;
	}
	print_menu(mlx);
}

int	julia_coordinates(int x, int y, t_mlx *mlx)
{
	mlx->constant_x_julia = 0.0;
	mlx->constant_y_julia = 0.0;
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
	{
		mlx->constant_y_julia = (y - WIN_H * 0.25) / (WIN_H * 0.25);
		mlx->constant_x_julia = (x - WIN_W * 0.25) / (WIN_W * 0.25);
	}
	julia_math(mlx);
	return (0);
}
