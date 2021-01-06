/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/06 16:44:12 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_fractalizer	*fractal_holder(int fractal)
{
	static t_fractalizer hold[9];

	if (!hold[0])
	{
		hold[0] = &mandelbrot;
		hold[1] = &julia;
		hold[2] = &burningship;
		hold[3] = &mandelbrot_flower;
	}
	return (&hold[fractal]);
}

void            menudisplay(void)
{
    t_fractol *f;

    f = fetchenv();
    mlx_string_put(f->mlx_server_ptr, f->mlx_win, WIDTH * 0.800, 300, 0xffffff, "Close window: ESC or RED CROSS.");
}