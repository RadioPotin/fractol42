/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:16 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/07 15:13:56 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_cleanclose(int key)
{
	t_fractol	*fractol;

	fractol = fetchenv();
	(void)key;
	mlx_destroy_image(fractol->mlx_server_ptr, fractol->mlx_img_ptr);
	free(fractol);
	exit(0);
}

int		ft_translate(int k)
{
	t_fractol *f;

	f = fetchenv();
	if (k == 123 || k == 124)
		f->trans_x += (k == 123) ? 0.080 : -0.080;
	else
		f->trans_y += (k == 126) ? 0.080 : -0.080;
	draw(f->fractal_type, f->requested_fractal);
	return (0);
}

int		ft_zoom(int k)
{
	t_fractol *f;

	f = fetchenv();
	if (k == 116)
	{
		f->x1 = (f->trans_x / (double)f->zoom + f->x1) - (f->trans_x / ((double)f->zoom * 1.25));
		f->y1 = (f->trans_y / (double)f->zoom + f->y1) - (f->trans_y / ((double)f->zoom * 1.25));
		f->zoom *= 1.25;
		draw(f->fractal_type, f->requested_fractal);
		return (1);
	}
	else
	{
		f->x1 = (f->trans_x / (double)f->zoom + f->x1) + (f->trans_x / ((double)f->zoom / 1.25));
		f->y1 = (f->trans_y / (double)f->zoom + f->y1) + (f->trans_y / ((double)f->zoom / 1.25));
		f->zoom /= 1.25;
		draw(f->fractal_type, f->requested_fractal);
	}
	return (1);
}

int		switch_palette(int k)
{
	(void)k;
	return (0);
}

int		do_nothing(int somekey)
{
	(void)somekey;
	return (0);
}
