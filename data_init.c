/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:42:58 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:47 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2 == NULL)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	mdb_init(t_fractal *f)
{
	f->offsety = 0.0;
	f->offsetx = 0.0;
	f->zoom = 1.0;
	f->color_in = WHITE;
	f->color_out = BLACK;
}

void	jl_init(t_fractal *f, char **argv, t_atoi *val)
{
	f->offsety = 0.0;
	f->offsetx = 0.0;
	f->zoom = 1.0;
	f->c.imag = atoi_double(argv[2], val);
	f->c.real = atoi_double(argv[3], val);
	f->color_in = WHITE;
	f->color_out = BLACK;
}

int	start(t_check *check, char **argv, int argc)
{
	check->str1 = "mandelbrot";
	check->str2 = "julia";
	check ->str3 = "burning_ship";
	check->mdb = ft_strcmp("mandelbrot", argv[1]);
	check->jl = ft_strcmp("julia", argv[1]);
	check->bs = ft_strcmp("burning_ship", argv[1]);
	if (check->mdb == 0 && argc == 2)
		return (1);
	else if (check->jl == 0 && argc == 4)
		return (2);
	else if (check->bs == 0 && argc == 2)
		return (3);
	return (0);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}
