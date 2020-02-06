/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:57 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/06 15:30:09 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		f->var.z_r = (x / f->zoom) + f->x1 + f->trans_x;
		f->var.z_i = (y / f->zoom) + f->y1 + f->trans_y;
		clear_image();
		draw(f->fractal_type, 1);
	}
	return (1);
}
