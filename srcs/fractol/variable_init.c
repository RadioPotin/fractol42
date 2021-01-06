/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:30:40 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/06 16:40:35 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		set_x1(int fractal)
{
	double	x1_values[9];

	x1_values[0] = -2.1;
	x1_values[1] = 0.285;
	x1_values[2] = -2.1;
	x1_values[3] = -2.5;
	return (x1_values[fractal]);
}

double		set_y1(int fractal)
{
	double	y1_values[9];

	y1_values[0] = -1.2;
	y1_values[1] = 0.013;
	y1_values[2] = -1.8;
	y1_values[3] = -1.9;
	return (y1_values[fractal]);
}

int			set_maxiter(int fractal)
{
	int		maxiter_values[9];

	maxiter_values[0] = 50;
	maxiter_values[1] = 50;
	maxiter_values[2] = 300;
	maxiter_values[3] = 50;
	return (maxiter_values[fractal]);
}

int			set_zoom(int fractal)
{
	int		zoom_values[9];

	zoom_values[0] = 450;
	zoom_values[1] = 450;
	zoom_values[2] = 300;
	zoom_values[3] = 400;
	return (zoom_values[fractal]);
}

double		set_trans_x(int fractal)
{
	double	trans_x_values[9];

	trans_x_values[0] = -0.5;
	trans_x_values[1] = -2.5;
	trans_x_values[2] = -1.0;
	trans_x_values[3] = 0.1;
	return (trans_x_values[fractal]);
}

double		set_trans_y(int fractal)
{
	double	trans_y_values[9];

	trans_y_values[0] = 0;
	trans_y_values[1] = -1.25;
	trans_y_values[2] = -0.20;
	trans_y_values[3] = 0.50;
	return (trans_y_values[fractal]);
}