/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:32:19 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/08 00:28:11 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_zoom(int key, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (key == SCROLL_DOWN)
	{
		mlx->x_axis_min *= 1.1;
		mlx->x_axis_max *= 1.1;
		mlx->y_axis_min *= 1.1;
		mlx->y_axis_max *= 1.1;
		mlx->pixel_length_x
			= ((mlx->x_axis_max - mlx->x_axis_min) / (WIN_W - 1));
		mlx->pixel_length_y
			= ((mlx->y_axis_max - mlx->y_axis_min) / (WIN_H - 1));
		mlx->x_offset /= 1.1;
		mlx->y_offset /= 1.1;
	}
	if (key == SCROLL_UP)
	{
		mlx->x_axis_min *= 0.9;
		mlx->x_axis_max *= 0.9;
		mlx->y_axis_min *= 0.9;
		mlx->y_axis_max *= 0.9;
		mlx->pixel_length_x
			= ((mlx->x_axis_max - mlx->x_axis_min) / (WIN_W - 1));
		mlx->pixel_length_y
			= ((mlx->y_axis_max - mlx->y_axis_min) / (WIN_H - 1));
		mlx->x_offset *= 1.1;
		mlx->y_offset *= 1.1;
	}
	if (mlx->pixel_length_y > 10 || mlx->pixel_length_x > 10
		|| mlx->pixel_length_y < 0.0000001 || mlx->pixel_length_x < 0.0000001)
		set_limits(mlx);
	draw(mlx);
	return (1);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
	{
		if (mlx->refresh == 1)
		{
			if (mlx->f_type == 2)
			{
				mlx->julia_x = x;
				mlx->julia_y = y;
			}
		}
		draw(mlx);
	}
	return (0);
}

int	mouse_down(int key, int x, int y, t_mlx *mlx)
{
	if (key == SCROLL_DOWN || key == SCROLL_UP)
		mouse_zoom(key, x, y, mlx);
	if (key == LEFT_CLICK)
	{
		if (mlx->refresh == 1)
			mlx->refresh = 0;
		else
			mlx->refresh = 1;
	}
	return (0);
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit_message(EXIT_ESC, EXIT_SUCCESS);
	if (key == RIGHT_KEY)
		mlx->x_offset += 100;
	if (key == LEFT_KEY)
		mlx->x_offset -= 100;
	if (key == DOWN_KEY)
		mlx->y_offset += 100;
	if (key == UP_KEY)
		mlx->y_offset -= 100;
	if (mlx->y_offset > 800000 || mlx->y_offset < -800000
		|| mlx->x_offset > 800000 || mlx->x_offset < -800000)
	{
		mlx->y_offset = 0;
		mlx->x_offset = 0;
	}
	draw(mlx);
	return (0);
}
