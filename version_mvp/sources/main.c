/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:05:55 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/23 14:08:14 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_limits(t_mlx *mlx)
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

static void	init_math(t_mlx *mlx)
{
	mlx->constant_x = 0.0;
	mlx->constant_y = 0.0;
	mlx->x_pixel = 0.0;
	mlx->y_pixel = 0.0;
	mlx->constant_x_julia = 0.0;
	mlx->constant_y_julia = 0.0;
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_message(EXIT_MLX_1, EXIT_ERROR);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, WIN_N);
	if (mlx->win == NULL)
		exit_message(EXIT_MLX_2, EXIT_ERROR);
	mlx->x = 0;
	mlx->y = 0;
	mlx->first_round = 1;
	mlx->color = 0;
	mlx->x_offset = 0;
	mlx->y_offset = 0;
	set_limits(mlx);
	init_math(mlx);
	mlx->pixel_length_x = (mlx->x_axis_max - mlx->x_axis_min) / (WIN_W - 1);
	mlx->pixel_length_y = (mlx->y_axis_max - mlx->y_axis_min) / (WIN_H - 1);
}

static void	fractal_type(char *argv, t_mlx *mlx)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		mlx->f_type = 1;
	else if (ft_strcmp(argv, "julia") == 0)
		mlx->f_type = 2;
	else if (ft_strcmp(argv, "tricorn") == 0)
		mlx->f_type = 3;
	else
		exit_message(EXIT_USAGE, EXIT_ERROR);
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;

	if (argc == 2)
	{
		fractal_type(argv[1], &mlx);
		init_mlx(&mlx);
		draw(mlx);
	}
	else
		exit_message(EXIT_USAGE, EXIT_ERROR);
	return (0);
}
