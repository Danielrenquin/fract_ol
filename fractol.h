/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:11:23 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 14:25:05 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/ftprintf/ft_printf.h"
# include "lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# define W 800
# define H 800
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define COLO_ADD 65451
# define COLO_MIN 65453 

typedef struct s_img
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_check
{
	char	*str1;
	char	*str2;
	char	*str3;
	int		mdb;
	int		jl;
	int		bs;
}	t_check;

typedef struct s_comp
{
	double	real;
	double	imag;
}	t_comp;

typedef struct s_draw
{
	int	x;
	int	y;
	int	iteration;
}	t_draw;

typedef struct s_atoi
{
	double	result;
	double	fraction;
	int		sign;
	int		divisor;
	int		i;
}	t_atoi;

typedef struct s_fractal
{
	t_img	img;
	t_draw	data;
	t_comp	c;
	void	*mlx_connection;
	void	*mlx_window;
	double	zoom;
	double	offsetx;
	double	offsety;
	int		choose;
	int		color_in;
	int		color_out;
}	t_fractal;

void	graphical_init(t_fractal *f);
int		ft_strcmp(char *s1, char *s2);
int		start(t_check *check, char **argv, int argc);
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);
int		jl(t_comp z, t_comp c, int max_iter);
int		mandelbrot(t_comp c, int max_iter);
int		burning_ship(t_comp c, int max_iter);
void	draw_mdb(int m_i, t_fractal *f);
void	draw_julia(int m_i, t_fractal *f);
void	draw_burning_ship(int m_i, t_fractal *f);
int		handle_input1(int keysym, t_fractal *f);
int		handle_input2(int keysym, t_fractal *f);
int		handle_input3(int keysym, t_fractal *f);
int		handle_in1(int button, int x, int y, t_fractal *f);
int		handle_in2(int button, int x, int y, t_fractal *f);
int		handle_in3(int button, int x, int y, t_fractal *f);
void	mdb_init(t_fractal *f);
void	jl_init(t_fractal *f, char **argv, t_atoi *val);
int		close_handler(t_fractal *f);
double	atoi_double(char *str, t_atoi *val);
void	atoi_init(t_atoi *val);
void	choose1(t_fractal *f);
void	choose2(t_fractal *f, char **argv, t_atoi *val);
void	choose3(t_fractal *f);

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PINK 0xFFC0CB
# define PURPLE 0x800080

#endif
