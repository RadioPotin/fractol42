/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:10:16 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/06 16:25:31 by dapinto          ###   ########.fr       */
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
	return (0);
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

int		switch_palette(int k)
{
	t_fractol *f;

	(void)k;
	f = fetchenv();
	f->eve.palet = (f->eve.palet + 1 < 4) ? f->eve.palet + 1 : 0;
	draw(f->fractal_type, f->requested_fractal);
	return (0);
}

int		do_nothing(int somekey)
{
	(void)somekey;
	return (0);
}

int		lockmvt(int k)
{
	t_fractol *f;

	f = fetchenv();
	if (f->eve.lock)
		f->eve.lock = k - k;
	else
		f->eve.lock = k;
	return (0);
}
