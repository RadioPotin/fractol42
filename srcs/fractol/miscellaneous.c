/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/06 16:12:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				clear_image(void)
{
	t_fractol	*f;
	int			i;

	i = 0;
	f = fetchenv();
	while (i < WIDTH * HEIGHT)
	{
		if (f->img_tab[i] != 0)
			f->img_tab[i] = 0;
		i++;
	}
}

static void			trigger_px(double x, double y)
{
	t_fractol	*f;
	long		i;
	int			*colour_table;

	f = fetchenv();
	colour_table = colour_tab(f->eve.palet);
	i = 0 + y * WIDTH + x;
	if (x >= 0 && f->var.iter < f->max_iteration)
		f->img_tab[i] = colour_table[f->var.iter % 16];
	else
		f->img_tab[i] = 0;
}

void				draw(t_fractalizer *fractal_type, int fractal)
{
	int			x;
	int			y;
	t_fractol	*fractol;
	t_compute	*fractal_compute;

	y = 0;
	fractol = fetchenv();
	fractal_compute = set_compute_struct(fractal);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*fractal_compute)(x, y);
			(*fractal_type)();
			trigger_px(x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win,
			fractol->mlx_img_ptr, 0, 0);
}
