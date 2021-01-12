/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:30:40 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/12 15:18:27 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double set_x1(int fractal)
{
	static double x1_values[9];

	if (!x1_values[0])
	{
		x1_values[0] = -2.1;
		x1_values[1] = 0.285;
		x1_values[2] = -2.1;
		x1_values[3] = -2.5;
	}
	return (x1_values[fractal]);
}

double set_y1(int fractal)
{
	static double y1_values[9];

	if (!y1_values[0])
	{
		y1_values[0] = -1.2;
		y1_values[1] = 0.013;
		y1_values[2] = -1.8;
		y1_values[3] = -1.75;
	}
	return (y1_values[fractal]);
}

double set_trans_x(int fractal)
{
	static double trans_x_values[9];

	if (!trans_x_values[0])
	{
		trans_x_values[0] = -0.5;
		trans_x_values[1] = -2.40;
		trans_x_values[2] = -1.0;
		trans_x_values[3] = 0.352;
	}
	return (trans_x_values[fractal]);
}

double set_trans_y(int fractal)
{
	static double trans_y_values[9];

	if (!trans_y_values[0])
	{
		trans_y_values[0] = 0.0;
		trans_y_values[1] = -1.2;
		trans_y_values[2] = -0.20;
		trans_y_values[3] = 0.50;
	}
	return (trans_y_values[fractal]);
}
