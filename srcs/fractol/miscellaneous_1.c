/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/11 10:57:55 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void				draw(void)
{
	int			x;
	int			y;
	t_fractol	*fractol;

	y = 0;
	fractol = fetchenv();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*fractol->fractal_compute)(x, y);
			(*fractol->fractal_type)();
			trigger_px(x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win,
			fractol->mlx_img_ptr, 0, 0);
}
