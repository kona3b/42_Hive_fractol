/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:05:55 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/08 00:28:24 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_event, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, exit_success, mlx);
	mlx_hook(mlx->win, ON_MOUSEMOVE, 0, mouse_move, mlx);
	mlx_hook(mlx->win, ON_MOUSEDOWN, 0, mouse_down, mlx);
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;

	if (argc == 2)
	{
		fractal_type(argv[1], &mlx);
		init_mlx(&mlx);
		hooks(&mlx);
		draw(&mlx);
		mlx_loop(&mlx);
	}
	else
		exit_message(EXIT_USAGE, EXIT_ERROR);
	return (0);
}
