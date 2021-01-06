/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/25 11:14:24 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractalizer	*fractal_holder(int fractal)
{
	static t_fractalizer hold[9];

	if (!hold[0])
	{
		hold[0] = &mandelbrot;
		hold[1] = &julia;
		hold[2] = &burningship;
		hold[3] = &mandelbrot_flower;
	}
	return (&hold[fractal]);
}

static void		mlx_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, 2, 0, event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 6, 0, &mouse_mvt, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, ft_cleanclose, &fractol);
	mlx_loop_hook(fractol->mlx_server_ptr, mouse_mvt, &fractol);
	mlx_mouse_hook(fractol->mlx_win, mouse_zm, fractol);
}

static int		ft_fractol(int fractal)
{
	t_fractol		*fractol;

	fractol = fetchenv();
	fractol->requested_fractal = fractal;
	initialize_variables(fractal);
	fractol->fractal_type = fractal_holder(fractal);
	draw(fractol->fractal_type, fractal);
	mlx_events(fractol);
	mlx_loop(fractol->mlx_server_ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	int			fractal;

	if ((fractal = get_arguments(argc, argv)) < 0)
	{
		if (fractal == -1)
			usage();
		else if (fractal == -2)
			print_fractal_list();
		return (fractal);
	}
	ft_fractol(fractal);
	return (0);
}
