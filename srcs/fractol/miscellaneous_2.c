/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/07 12:50:53 by dapinto          ###   ########.fr       */
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

static void		menudisplay_sets(void)
{
	t_fractol *f;

	f = fetchenv();
	if (f->requested_fractal == 0)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 300,
			0xffffff, "Current set   : Mandelbrot");
	else if (f->requested_fractal == 1)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 300,
			0xffffff, "Current set   : Julia");
	else if (f->requested_fractal == 2)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 300,
			0xffffff, "Current set   : Burning Ship");
	else if (f->requested_fractal == 3)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 300,
			0xffffff, "Current set   : Mandelbrot Flower");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 350,
		0xffffff, "Change set    : 0 to 3 on Numpad");
}

void			menudisplay(void)
{
	t_fractol *f;

	f = fetchenv();
	menudisplay_sets();
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 400, 0xffffff,
		"Lock ON / OFF : Space bar");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 450, 0xffffff,
		"Colour change : C");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 500, 0xffffff,
		"Move Fractal  : UP/DOWN/LEFT/RIGHT arrows");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 550, 0xffffff,
		"Zoom on coord : Left Mouse Button");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 600, 0xffffff,
		"Default Zoom  : Mouse Wheel");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 650, 0xffffff,
		"Reset         : HOME");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.775, 700, 0xffffff,
		"Close window  : ESC or RED CROSS");
}
