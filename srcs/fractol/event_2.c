/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:57 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/07 15:48:40 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_reset(int k)
{
	t_fractol *f;

	f = fetchenv();
	(void)k;
	initialize_variables(f->requested_fractal);
	draw(f->fractal_type, f->requested_fractal);
	return (1);
}

int		ft_switch(int k)
{
	t_fractol *fractol;

	k -= 82;
	fractol = fetchenv();
	fractol->requested_fractal = k;
	initialize_variables(k);
	fractol->fractal_type = fractal_holder(k);
	draw(fractol->fractal_type, k);
	return (1);
}

int		mouse_zm(int k, int x, int y)
{
	(void)k;
	(void)x;
	(void)y;

	return (0);
}

int		mouse_mvt(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	if (f->requested_fractal == 1 && x > 0 && x < WIDTH && y > 0
				&& y < HEIGHT)
	{
		f->julia_r = (double)x / f->zoom + f->x1 + f->trans_x;
		f->julia_i = (double)y / f->zoom + f->y1 + f->trans_y;
		draw(f->fractal_type, 1);
	}
	return (1);
}
