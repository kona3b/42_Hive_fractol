/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:58:22 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/04 19:11:05 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static void	print_menu(t_mlx *mlx)
{
	int	y;

	y = 0;
	if (mlx->f_type == 2)
	{
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "'ESC': EXIT");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Move mouse: edit julia");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Left click: refresh on/off");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Arrows: move");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Scroll: zoom");
	}
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "'ESC': EXIT");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Arrows: move");
		mlx_string_put(mlx->mlx, mlx->win, 20, y += 20,
			COLOR_S, "Scroll: zoom");
	}
}

void	draw(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.img == NULL || mlx->img.addr == NULL)
		exit_message(EXIT_MLX_3, EXIT_ERROR);
	fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	print_menu(mlx);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
}
