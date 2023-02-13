/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:59:41 by kaittola          #+#    #+#             */
/*   Updated: 2022/11/08 00:23:05 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"

# define MAX_ITER 64
# define WIN_H 600
# define WIN_W 800
# define WIN_N "fractol-kaittola"

# define EXIT_WINDOW "Window closed, successful exit!\n"
# define EXIT_USAGE "Usage: ./fractol <fractal name> (julia, mandelbrot, \
tricorn)\n"
# define EXIT_ESC "Esc pressed, successfull exit!\n"
# define EXIT_MLX_1 "mlx->mlx is NULL error!\n"
# define EXIT_MLX_2 "mlx->win is NULL error!\n"
# define EXIT_MLX_3 "mlx->img.img or mlx->img.addr is NULL error!\n"

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define COLOR_A 0x37294f
# define COLOR_B 0x082567
# define COLOR_C 0xfcff5d
# define COLOR_D 0xf47a22
# define COLOR_E 0x77DD77
# define COLOR_F 0x228c68
# define COLOR_G 0x8ad8e8
# define COLOR_H 0x235b54
# define COLOR_I 0x991919
# define COLOR_J 0xFF00FF
# define COLOR_K 0xFF6700
# define COLOR_L 0x7dfc00
# define COLOR_M 0x87CEEB
# define COLOR_N 0xf22020
# define COLOR_O 0x29bdab
# define COLOR_P 0xffcba5
# define COLOR_Q 0xe68f66
# define COLOR_R 0xc56133
# define COLOR_S 0x66FF00
# define COLOR_T 0x632819
# define COLOR_U 0xffc413
# define COLOR_V 0x277da7

enum e_key
{
	KEY_ESC = 53,
	UP_KEY = 126,
	DOWN_KEY = 125,
	LEFT_KEY = 123,
	RIGHT_KEY = 124
};

enum e_mouse
{
	MOVE = 0,
	LEFT_CLICK = 1,
	SCROLL_UP = 5,
	SCROLL_DOWN = 4
};

enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			f_type;
	long double		x_offset;
	long double		y_offset;

	int			y;
	int			x;
	int			color;
	int			iterations;

	long double		pixel_length_x;
	long double		pixel_length_y;

	long double		x_axis_min;
	long double		x_axis_max;
	long double		y_axis_min;
	long double		y_axis_max;

	long double		constant_y;
	long double		constant_x;
	long double		constant_y_2;
	long double		constant_x_2;

	long double		y_pixel;
	long double		x_pixel;
	long double		julia_y;
	long double		julia_x;

	int			refresh;
}				t_mlx;

/* ------------------------------- Main ------------------------------------- */

void		print_error(char *reason);
int			check_fractal_type(int ac, char **av);

/* ------------------------------- Draw ------------------------------------- */

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		draw(t_mlx *mlx);

/* ------------------------------- Inits ------------------------------------- */

void		init_mlx(t_mlx *mlx);
void		set_limits(t_mlx *mlx);

/* ----------------------------- Controls ----------------------------------- */

int			key_event(int key, t_mlx *mlx);
int			mouse_down(int key, int x, int y, t_mlx *mlx);
int			mouse_up(int key, int x, int y, t_mlx *mlx);
int			mouse_move(int x, int y, t_mlx *mlx);

/* ---------------------------- Fractals ------------------------------------ */

void		fractal(t_mlx *mlx);

/* ----------------------------- Colors ----------------------------------- */

int			set_color(int c);

/* ------------------------------ Exit -------------------------------------- */

void		exit_message(const char *msg, int v);
int			exit_success(void);

#endif
