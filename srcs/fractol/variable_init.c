/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:30:40 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/25 12:45:09 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	set_x1(int fractal)
{
	double	x1_values[9];

	x1_values[0] = -2.1;
	x1_values[1] = 0.285;
	x1_values[2] = -2.1;
	return (x1_values[fractal]);
}

static double	set_y1(int fractal)
{
	double	y1_values[9];

	y1_values[0] = -1.2;
	y1_values[1] = 0.013;
	y1_values[2] = -1.8;
	return (y1_values[fractal]);
}

static int	set_maxiter(int fractal)
{
	int		maxiter_values[9];

	maxiter_values[0] = 50;
	maxiter_values[1] = 50;
	maxiter_values[2] = 300;
	return (maxiter_values[fractal]);
}

static int	set_zoom(int fractal)
{
	int		zoom_values[9];

	zoom_values[0] = 450;
	zoom_values[1] = 450;
	zoom_values[2] = 300;
	return (zoom_values[fractal]);
}

double			set_trans_x(int fractal)
{
	double	trans_x_values[9];

	trans_x_values[0] = -0.5;
	trans_x_values[1] = -2.5;
	trans_x_values[2] = -1.0;
	return (trans_x_values[fractal]);
}

double			set_trans_y(int fractal)
{
	double	trans_y_values[9];

	trans_y_values[0] = 0;
	trans_y_values[1] = -1.25;
	trans_y_values[2] = -0.20;
	return (trans_y_values[fractal]);
}

void			initialize_variables(int fractal)
{
	t_fractol	*frac;

	frac = fetchenv();
	frac->x1 = set_x1(fractal);
	frac->y1 = set_y1(fractal);
	if (fractal == 1)
	{
		frac->julia_r = frac->x1;
		frac->julia_i = frac->y1;
	}
	frac->max_iteration = set_maxiter(fractal);
	frac->zoom = set_zoom(fractal);
	frac->trans_x = set_trans_x(fractal);
	frac->trans_y = set_trans_y(fractal);
}
