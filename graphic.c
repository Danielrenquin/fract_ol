/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:53:59 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 14:30:21 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	graphical_init(t_fractal *f)
{
	f->mlx_connection = mlx_init();
	if (f->mlx_connection == NULL)
		return ;
	f->mlx_window = mlx_new_window(f->mlx_connection, W, H, "fract-ol");
	if (f->mlx_window == NULL)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		return ;
	}
	f->img.img_ptr = mlx_new_image(f->mlx_connection, W, H);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		return ;
	}
	f->img.pixel_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
}

void	put_pixel(int x, int y, t_fractal *f, int color)
{
	int	offset;

	offset = (y * f->img.line_len) + (x * (f->img.bpp / 8));
	*(unsigned int *)(f->img.pixel_ptr + offset) = color;
}

void	draw_mdb(int m_i, t_fractal *f)
{
	t_comp	c;
	int		color;

	f->data.x = 0;
	f->data.y = 0;
	while (f->data.x++ < H)
	{
		while (f->data.y++ < W)
		{
			c.real = ((f->data.x - W / 2.0) * 4.0 / W) / f->zoom + f->offsetx;
			c.imag = ((f->data.y - H / 2.0) * 4.0 / H) / f->zoom + f->offsety;
			f->data.iteration = mandelbrot(c, m_i);
			if (f->data.iteration == m_i)
				put_pixel(f->data.x, f->data.y, f, PURPLE);
			else
			{
				color = map(f->data.iteration, f->color_in, f->color_out, m_i);
				put_pixel(f->data.x, f->data.y, f, color);
			}
		}
		f->data.y = 0;
	}
	mlx_put_image_to_window(f->mlx_connection,
		f->mlx_window, f->img.img_ptr, 0, 0);
}

void	draw_julia(int m_i, t_fractal *f)
{
	t_comp	z;
	int		color;

	f->data.x = 0;
	f->data.y = 0;
	while (f->data.x++ < H)
	{
		while (f->data.y++ < W)
		{
			z.real = ((f->data.x - W / 2.0) * 4.0 / W) / f->zoom + f->offsetx;
			z.imag = ((f->data.y - H / 2.0) * 4.0 / H) / f->zoom + f->offsety;
			f->data.iteration = jl(z, f->c, m_i);
			if (f->data.iteration == m_i)
				put_pixel(f->data.x, f->data.y, f, PURPLE);
			else
			{
				color = map(f->data.iteration, f->color_in, f->color_out, m_i);
				put_pixel(f->data.x, f->data.y, f, color);
			}
		}
		f->data.y = 0;
	}
	mlx_put_image_to_window(f->mlx_connection,
		f->mlx_window, f->img.img_ptr, 0, 0);
}

void	draw_burning_ship(int m_i, t_fractal *f)
{
	t_comp	c;
	int		col;

	f->data.x = 0;
	f->data.y = 0;
	while (f->data.x++ < H)
	{
		while (f->data.y++ < W)
		{
			c.real = ((f->data.x - W / 2.0) * 4.0 / W) / f->zoom + f->offsetx;
			c.imag = ((f->data.y - H / 2.0) * 4.0 / H) / f->zoom + f->offsety;
			c.imag = -c.imag;
			f->data.iteration = burning_ship(c, m_i);
			if (f->data.iteration == m_i)
				put_pixel(f->data.x, f->data.y, f, PURPLE);
			else
			{
				col = map(f->data.iteration, f->color_in, f->color_out, m_i);
				put_pixel(f->data.x, f->data.y, f, col);
			}
		}
		f->data.y = 0;
	}
	mlx_put_image_to_window(f->mlx_connection,
		f->mlx_window, f->img.img_ptr, 0, 0);
}
