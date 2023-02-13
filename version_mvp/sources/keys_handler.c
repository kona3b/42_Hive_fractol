/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:55:01 by kaittola          #+#    #+#             */
/*   Updated: 2022/10/22 23:14:38 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit_message(EXIT_ESC, EXIT_SUCCESS);
	if (mlx->f_type != 2)
	{
		if (key == RIGHT_KEY)
			mlx->x_offset += 100;
		if (key == LEFT_KEY)
			mlx->x_offset -= 100;
		if (key == DOWN_KEY)
			mlx->y_offset += 100;
		if (key == UP_KEY)
			mlx->y_offset -= 100;
		if (mlx->y_offset > 800000 || mlx->y_offset < -800000)
			mlx->y_offset = 0;
		if (mlx->x_offset > 800000 || mlx->x_offset < -800000)
			mlx->x_offset = 0;
	}
	if (mlx->f_type == 1)
		mandelbrot_math(*mlx);
	if (mlx->f_type == 2)
		mlx_hook(mlx->win, 6, 0, julia_coordinates, mlx);
	if (mlx->f_type == 3)
		tricorn_math(*mlx);
	return (0);
}
