/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:36:50 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/13 11:38:40 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_maxiter(int fractal)
{
	static int maxiter_values[9];

	if (!maxiter_values[0])
	{
		maxiter_values[0] = 50;
		maxiter_values[1] = 50;
		maxiter_values[2] = 300;
		maxiter_values[3] = 50;
	}
	return (maxiter_values[fractal]);
}

int		set_zoom(int fractal)
{
	static int zoom_values[9];

	if (!zoom_values[0])
	{
		zoom_values[0] = 300;
		zoom_values[1] = 300;
		zoom_values[2] = 250;
		zoom_values[3] = 300;
	}
	return (zoom_values[fractal]);
}
