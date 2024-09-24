/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:36:14 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 14:33:49 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	complex_add(t_comp a, t_comp b)
{
	t_comp	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_comp	complex_mul(t_comp a, t_comp b)
{
	t_comp	result;

	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return (result);
}

int	mandelbrot(t_comp c, int max_iter)
{
	t_comp	z;
	int		i;

	i = 0;
	z.real = 0.0;
	z.imag = 0.0;
	while (i < max_iter)
	{
		z = complex_add(complex_mul(z, z), c);
		if (((z.real * z.real) + (z.imag * z.imag)) > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

int	jl(t_comp z, t_comp c, int max_iter)
{
	int	i;

	i = 0;
	while (i < max_iter)
	{
		z = complex_add(complex_mul(z, z), c);
		if (((z.real * z.real) + (z.imag * z.imag)) > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

int	burning_ship(t_comp c, int max_iter)
{
	t_comp	z;
	t_comp	z_abs;
	int		i;

	i = 0;
	z.real = 0.0;
	z.imag = 0.0;
	while (i < max_iter)
	{
		z_abs.real = fabs(z.real);
		z_abs.imag = fabs(z.imag);
		z = complex_add(complex_mul(z_abs, z_abs), c);
		if (((z.real * z.real) + (z.imag * z.imag)) > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}
