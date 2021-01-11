/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:57 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/11 10:57:55 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_reset(int k)
{
	t_fractol *f;

	f = fetchenv();
	(void)k;
	initialize_variables(f->requested_fractal);
	draw();
	return (1);
}

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

int	ft_switch(int k)
{
	t_fractol *fractol;

	k -= 82;
	if (k < 4)
	{
		fractol = fetchenv();
		fractol->requested_fractal = k;
		initialize_variables(k);
		fractol->fractal_type = fractal_holder(k);
		fractol->fractal_compute = set_compute_struct(k);
		draw();
	}
	return (1);
}

int	mouse_zm(int k, int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	if ((k == 1 || k == 2 || k == 4 || k == 5) &&
		(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == 2)
		{
			f->x1 = ((double)x / f->zm + f->x1) - ((double)x / (f->zm / 1.25));
			f->y1 = ((double)y / f->zm + f->y1) - ((double)y / (f->zm / 1.25));
		}
		k == 2 || k == 5 ? f->zm /= 1.25 : 0.0;
		if (k == 1)
		{
			f->x1 = ((double)x / f->zm + f->x1) - ((double)x / (f->zm * 1.25));
			f->y1 = ((double)y / f->zm + f->y1) - ((double)y / (f->zm * 1.25));
		}
		k == 1 || k == 4 ? f->zm *= 1.25 : 0.0;
		draw();
		menudisplay();
	}
	return (1);
}

int	mouse_mvt(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	if (!f->eve.lock && f->requested_fractal == 1
		&& x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		f->julia_r = (double)x / f->zm + f->x1 + f->trans_x;
		f->julia_i = (double)y / f->zm + f->y1 + f->trans_y;
		f->requested_fractal = 1;
		f->fractal_type = fractal_holder(1);
		f->fractal_compute = set_compute_struct(1);
		draw();
		menudisplay();
	}
	return (1);
}
