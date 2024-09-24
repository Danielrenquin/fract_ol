/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:28:18 by drenquin          #+#    #+#             */
/*   Updated: 2024/09/24 10:35:10 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose1(t_fractal *f)
{
	mdb_init(f);
	draw_mdb(400, f);
	mlx_key_hook(f->mlx_window, handle_input1, f);
	mlx_mouse_hook(f->mlx_window, handle_in1, f);
}

void	choose2(t_fractal *f, char **argv, t_atoi *val)
{
	jl_init(f, argv, val);
	draw_julia(400, f);
	mlx_key_hook(f->mlx_window, handle_input2, f);
	mlx_mouse_hook(f->mlx_window, handle_in2, f);
}

void	choose3(t_fractal *f)
{
	mdb_init(f);
	draw_burning_ship(400, f);
	mlx_key_hook(f->mlx_window, handle_input3, f);
	mlx_mouse_hook(f->mlx_window, handle_in3, f);
}

int	main(int argc, char **argv)
{
	t_fractal	f;
	t_check		check;
	t_atoi		val;

	f.choose = start(&check, argv, argc);
	if (f.choose != 0)
	{
		graphical_init(&f);
		if (f.choose == 1)
			choose1(&f);
		else if (f.choose == 2)
			choose2(&f, argv, &val);
		else if (f.choose == 3)
			choose3(&f);
		mlx_hook(f.mlx_window, DestroyNotify,
			StructureNotifyMask, close_handler, &f);
		mlx_loop(f.mlx_connection);
	}
	if (f.choose == 0)
	{
		ft_printf("compile with ./fractol mandelbrot\n");
		ft_printf("or with ./fractol burning_ship\n");
		ft_printf("for julia ./fractol julia <value1> <value2>\n");
	}
}
