/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:29 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/07 23:56:51 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_limits(t_mlx *mlx)
{
	if (mlx->f_type == 2)
	{
		mlx->iterations = MAX_ITER;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 2.0;
		mlx->y_axis_min = -2.0;
		mlx->y_axis_max = 2.0;
	}
	else
	{
		mlx->iterations = MAX_ITER;
		mlx->x_axis_min = -2.0;
		mlx->x_axis_max = 1.0;
		mlx->y_axis_min = -1.12;
		mlx->y_axis_max = 1.12;
	}
	mlx->julia_x = WIN_W / 2;
	mlx->julia_y = WIN_H / 2;
	mlx->pixel_length_x = (mlx->x_axis_max - mlx->x_axis_min) / (WIN_W - 1);
	mlx->pixel_length_y = (mlx->y_axis_max - mlx->y_axis_min) / (WIN_H - 1);
}

static void	init_vars(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->color = 0;
	mlx->x_offset = 0.0;
	mlx->y_offset = 0.0;
	mlx->constant_x = 0.0;
	mlx->constant_y = 0.0;
	mlx->x_pixel = 0.0;
	mlx->y_pixel = 0.0;
	mlx->constant_x_2 = 0.0;
	mlx->constant_y_2 = 0.0;
	mlx->refresh = 1;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_message(EXIT_MLX_1, EXIT_ERROR);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, WIN_N);
	if (mlx->win == NULL)
		exit_message(EXIT_MLX_2, EXIT_ERROR);
	init_vars(mlx);
	set_limits(mlx);
	mlx_do_key_autorepeaton(mlx);
}
