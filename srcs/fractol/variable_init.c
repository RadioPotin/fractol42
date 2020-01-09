/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:30:40 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/09 18:27:09 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	set_x1(int fractal)
{
	double x1_values[2];
	x1_values[0] = -2.1;
	return (x1_values[fractal]);
}

static double	set_y1(int fractal)
{
	double y1_values[2];
	y1_values[0] = -1.2;
	return (y1_values[fractal]);
}

static double	set_maxiter(int fractal)
{
	double maxiter_values[2];
	maxiter_values[0] = 50;
	return (maxiter_values[fractal]);
}

static double	set_zoom(int fractal)
{
	double zoom_values[2];
	zoom_values[0] = 450;
	return (zoom_values[fractal]);
}

void			initialize_variables(int fractal)
{
	t_fractol *frac;

	frac = fetchenv();
	frac->x1 = set_x1(fractal);
	frac->y1 = set_y1(fractal);
	frac->max_iteration = set_maxiter(fractal);
	frac->zoom = set_zoom(fractal);
}
