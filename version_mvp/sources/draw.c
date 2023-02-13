/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:58:22 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/23 14:46:57 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_mlx mlx)
{
	mlx.first_round = 0;
	if (mlx.f_type == 1)
		mandelbrot_math(mlx);
	if (mlx.f_type == 2)
		julia_coordinates(WIN_W / 2, WIN_H / 2, &mlx);
	if (mlx.f_type == 3)
		tricorn_math(mlx);
}

void	print_menu(t_mlx *mlx)
{
	int	y;

	y = 0;
	if (mlx->f_type == 2)
	{
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "'ESC' to EXIT");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Move mouse to edit julia");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Mouse scroll to zoom");
	}
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "'ESC' to EXIT");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "ARROW KEYS to MOVE");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Mouse scroll to zoom");
	}
}

void	draw(t_mlx mlx)
{
	if (mlx.first_round == 1)
		init_fractal(mlx);
	mlx_hook(mlx.win, 17, 0, &exit_success, &mlx);
	if (mlx.f_type == 2)
		mlx_hook(mlx.win, 6, 0, &julia_coordinates, &mlx);
	mlx_mouse_hook(mlx.win, mouse_actions, &mlx);
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.mlx);
}
