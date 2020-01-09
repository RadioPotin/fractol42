/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/09 16:16:21 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				draw(t_fractalizer *f)
{
	int x;
	int y;
	t_fractol *fractol;

	y = 0;
	fractol = fetchenv();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_comp_mandel(x, y);
			(*f)();
			trigger_px(x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win,
			fractol->mlx_img_ptr, 0, 0);
}

static t_fractalizer	*fractal_holder(int fractal)
{
	static t_fractalizer hold[9];

	if (!hold[0])
	{
		hold[0] = &mandelbrot;
		//hold[0] = &julia();
		//hold[2] = &julia;
		//hold[3] = &julia;
	}
	return (&hold[fractal]);
}

static int				ft_fractol(int fractal)
{
	t_fractol		*fractol;

	fractol = fetchenv();
	initialize_variables();
	fractol->fractal_type = fractal_holder(fractal);
	draw(fractol->fractal_type);

	mlx_hook(fractol->mlx_win, 2, 0, &event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, &ft_cleanclose, &fractol);
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
