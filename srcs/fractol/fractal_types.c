/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:43:39 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/12 11:23:21 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(int maxiter, t_comp *comp)
{
	double		tmp;
	int			n;
	t_comp		*var;

	var = comp;
	n = var->z_r * var->z_r + var->z_i * var->z_i;
	while (n < 4 && var->iter < maxiter)
	{
		tmp = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = 2.0 * var->z_i * var->z_r + var->c_i;
		var->z_r = tmp;
		var->iter++;
		n = var->z_r * var->z_r + var->z_i * var->z_i;
	}
	return (0);
}

int		julia(int maxiter, t_comp *comp)
{
	int			n;
	double		tmp;
	t_comp		*var;

	var = comp;
	n = var->z_r * var->z_r + var->z_i * var->z_i;
	while (n < 4 && var->iter < maxiter)
	{
		tmp = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = 2.0 * var->z_i * var->z_r + var->c_i;
		var->z_r = tmp;
		var->iter++;
		n = var->z_r * var->z_r + var->z_i * var->z_i;
	}
	return (0);
}

int		burningship(int maxiter, t_comp *comp)
{
	int			n;
	double		tmp;
	t_comp		*var;

	var = comp;
	n = var->z_r * var->z_r + var->z_i * var->z_i;
	while (var->iter++ < maxiter && n < 4)
	{
		tmp = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = fabs(2 * var->z_r * var->z_i) + var->c_i;
		var->z_r = tmp;
		n = var->z_r * var->z_r + var->z_i * var->z_i;
	}
	return (0);
}

int		mandelbrot_flower(int maxiter, t_comp *comp)
{
	double		n;
	double		t;
	t_comp		*var;

	var = comp;
	n = pow(var->z_r, 6) + pow(var->z_i, 6);
	t = 0;
	while (var->iter++ < maxiter && n < 2)
	{
		t = var->z_r;
		var->z_r = pow(var->z_r, 6) - (15 * pow(var->z_r, 4)
			* pow(var->z_i, 2)) + (15 * pow(var->z_r, 2)
				* pow(var->z_i, 4)) - pow(var->z_i, 6) + var->c_i;
		var->z_i = (6 * pow(t, 5) * var->z_i - 20 * pow(t, 3)
			* pow(var->z_i, 3) + 6 * t
				* pow(var->z_i, 5)) + var->c_r;
		n = pow(var->z_r, 6) + pow(var->z_i, 6);
	}
	return (0);
}
