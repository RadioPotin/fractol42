/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:43:39 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/25 10:50:16 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(void)
{
	t_fractol	*f;
	double		tmp;
	int			n;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (n < 4 && f->var.iter < f->max_iteration)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = 2.0 * f->var.z_i * f->var.z_r + f->var.c_i;
		f->var.z_r = tmp;
		f->var.iter++;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}

int		julia(void)
{
	t_fractol	*f;
	int			n;
	double		tmp;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (n < 4 && f->var.iter < f->max_iteration)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = 2.0 * f->var.z_i * f->var.z_r + f->var.c_i;
		f->var.z_r = tmp;
		f->var.iter++;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}

int		burningship(void)
{
	int			n;
	double		tmp;
	t_fractol	*f;

	f = fetchenv();
	n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	while (f->var.iter++ < f->max_iteration && n < 4)
	{
		tmp = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i + f->var.c_r;
		f->var.z_i = fabs(2 * f->var.z_r * f->var.z_i) + f->var.c_i;
		f->var.z_r = tmp;
		n = f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i;
	}
	return (0);
}

int		mandelbrot_flower(void)
{
	double n;
	double t;
	t_fractol *f;

	f = fetchenv();
	n = pow(f->var.z_r, 6) + pow(f->var.z_i, 6);
	t = 0;
	while (f->var.iter++ < f->max_iteration && n < 2)
	{
		t = f->var.z_r;
		f->var.z_r = pow(f->var.z_r, 6) - (15 * pow(f->var.z_r, 4) * pow(f->var.z_i, 2)) +
			(15 * pow(f->var.z_r, 2) * pow(f->var.z_i, 4)) - pow(f->var.z_i, 6) + f->var.c_i;
		f->var.z_i = (6 * pow(t, 5) * f->var.z_i - 20 * pow(t, 3) *
				pow(f->var.z_i, 3) + 6 * t * pow(f->var.z_i, 5)) + f->var.c_r;
		n = pow(f->var.z_r, 6) + pow(f->var.z_i, 6);
	}
	return (0);
}