/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:32:19 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/23 14:13:30 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_limits_default(t_mlx *mlx)
{
	if (mlx->f_type == 2)
	{
		mlx->iterations = 64;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 2.0;
		mlx->y_axis_min = -2.0;
		mlx->y_axis_max = 2.0;
	}
	else
	{
		mlx->iterations = 30;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 1.0;
		mlx->y_axis_min = -1.12;
		mlx->y_axis_max = 1.12;
	}
}

static void	mouse_zoom(t_mlx *mlx, int key)
{
	if (key == SCROLL_DOWN)
	{
		mlx->x_axis_min *= 0.97;
		mlx->x_axis_max *= 0.97;
		mlx->y_axis_min *= 0.97;
		mlx->y_axis_max *= 0.97;
	}
	if (key == SCROLL_UP)
	{
		mlx->x_axis_min *= 1.03;
		mlx->x_axis_max *= 1.03;
		mlx->y_axis_min *= 1.03;
		mlx->y_axis_max *= 1.03;
	}
}

int	mouse_actions(int key, int x, int y, t_mlx *mlx)
{
	mouse_zoom(mlx, key);
	mlx->pixel_length_x
		= (mlx->x_axis_max - mlx->x_axis_min) / (WIN_W - 1);
	mlx->pixel_length_y
		= (mlx->y_axis_max - mlx->y_axis_min) / (WIN_H - 1);
	if (mlx->pixel_length_y > 10 || mlx->pixel_length_x > 10)
		set_limits_default(mlx);
	if (mlx->pixel_length_y < 0.0000001 || mlx->pixel_length_x < 0.0000001)
		set_limits_default(mlx);
	if (mlx->f_type == 1)
		mandelbrot_math(*mlx);
	if (mlx->f_type == 2)
		julia_coordinates(x, y, mlx);
	if (mlx->f_type == 3)
		tricorn_math(*mlx);
	return (0);
}
