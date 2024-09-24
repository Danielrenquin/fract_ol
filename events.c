/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:20 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 13:34:08 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_input1(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	else if (keysym == UP)
		f->offsety -= 0.1 / f->zoom;
	else if (keysym == DOWN)
		f->offsety += 0.3 / f->zoom;
	else if (keysym == LEFT)
		f->offsetx -= 0.3 / f->zoom;
	else if (keysym == RIGHT)
		f->offsetx += 0.3 / f->zoom;
	else if (keysym == COLO_ADD)
		f->color_in += 100;
	else if (keysym == COLO_MIN)
		f->color_in -= 100;
	draw_mdb(400, f);
	return (0);
}

int	handle_input2(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	else if (keysym == UP)
		f->offsety -= 0.1 / f->zoom;
	else if (keysym == DOWN)
		f->offsety += 0.3 / f->zoom;
	else if (keysym == LEFT)
		f->offsetx -= 0.3 / f->zoom;
	else if (keysym == RIGHT)
		f->offsetx += 0.3 / f->zoom;
	else if (keysym == COLO_ADD)
		f->color_in += 100;
	else if (keysym == COLO_MIN)
		f->color_in -= 100;
	draw_julia(400, f);
	return (0);
}

int	handle_input3(int keysym, t_fractal *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	else if (keysym == UP)
		f->offsety -= 0.1 / f->zoom;
	else if (keysym == DOWN)
		f->offsety += 0.3 / f->zoom;
	else if (keysym == LEFT)
		f->offsetx -= 0.3 / f->zoom;
	else if (keysym == RIGHT)
		f->offsetx += 0.3 / f->zoom;
	else if (keysym == COLO_ADD)
		f->color_in += 100;
	else if (keysym == COLO_MIN)
		f->color_in -= 100;
	draw_burning_ship(400, f);
	return (0);
}

int	handle_in3(int button, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.3;
	if (button == 4 || button == 5)
	{
		mouse_re = (double)x / (W / (2.0 - (-2.0))) - 2.0;
		mouse_im = (double)y / (H / (2.0 - (-2.0))) - 2.0;
		if (button == 4)
			f->zoom *= zoom_factor;
		else if (button == 5)
			f->zoom /= zoom_factor;
		f->offsetx = mouse_re - (mouse_re - f->offsetx) / zoom_factor;
		f->offsety = mouse_im - (mouse_im - f->offsety) / zoom_factor;
	}
	draw_burning_ship(400, f);
	return (0);
}

int	handle_in2(int button, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.3;
	if (button == 4 || button == 5)
	{
		mouse_re = (double)x / (W / (2.0 - (-2.0))) - 2.0;
		mouse_im = (double)y / (H / (2.0 - (-2.0))) - 2.0;
		if (button == 4)
			f->zoom *= zoom_factor;
		else if (button == 5)
			f->zoom /= zoom_factor;
		f->offsetx = mouse_re - (mouse_re - f->offsetx) / zoom_factor;
		f->offsety = mouse_im - (mouse_im - f->offsety) / zoom_factor;
	}
	draw_julia(400, f);
	return (0);
}
