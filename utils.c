/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:50:15 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 15:55:57 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	atoi_init(t_atoi *val)
{
	val->result = 0.0;
	val->fraction = 0.0;
	val->sign = 1;
	val->divisor = 1;
	val->i = 0;
}

double	atoi_double(char *str, t_atoi *val)
{
	atoi_init(val);
	while (str[val->i] == 32 || (str[val->i] >= 7 && str[val->i] <= 13))
		val->i++;
	if (str[val->i] == '-' || str[val->i] == '+')
	{
		if (str[val->i] == '-')
			val->sign = -1;
		val->i++;
	}
	while (str[val->i] && ft_isdigit(str[val->i]))
		val->result = val->result * 10 + (str[val->i++] - '0');
	if (str[val->i] == '.')
	{
		val->i++;
		while (str[val->i] && ft_isdigit(str[val->i]))
		{
			val->fraction = val->fraction * 10 + (str[val->i] - '0');
			val->divisor *= 10;
			val->i++;
		}
		val->result += val->fraction / val->divisor;
	}
	return (val->sign * val->result);
}

int	handle_in1(int button, int x, int y, t_fractal *f)
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
	draw_mdb(400, f);
	return (0);
}

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	mlx_destroy_window(f->mlx_connection, f->mlx_window);
	mlx_destroy_display(f->mlx_connection);
	free(f->mlx_connection);
	exit(1);
}
