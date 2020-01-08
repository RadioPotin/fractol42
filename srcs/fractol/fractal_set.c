/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:28:29 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/08 17:40:28 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(void)
{
	return (0);
}

int mandelbrot(void)
{
	t_fractol *f;
	double tmp;
	int n;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (n < 4 && f->var.iter < f->max_iteration)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = 2 * f->var.z_i * f->var.z_r + f->var.c_i;
		f->var.z_r = tmp;
		f->var.iter++;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}

void	set_comp_mandel(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	f->var.c_r = (x / f->zoom) + f->x1;//+ offsetx (donc forget init offsetx and y) 
	f->var.c_i = (y / f->zoom) + f->y1;
	f->var.z_r = 0;
	f->var.z_i = 0;
	f->var.iter = 0;
}

void	draw(t_fractalizer *f)
{
	int x;
	int y;
	t_fractol *fractol;

	fractol = fetchenv();
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			set_comp_mandel(x, y);
			(*f)();
			trigger_px(x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win, fractol->mlx_img_ptr, 0, 0);
}
