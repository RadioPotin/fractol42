/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:28:29 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/09 18:11:29 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_comp_mandel(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	ft_bzero(&f->var, sizeof(t_comp));
	f->var.c_r = (double)x / f->zoom + f->x1;
	f->var.c_i = (double)y / f->zoom + f->y1;
}

t_compute		*set_compute_struct(int fractal)
{
	static t_compute compute_struct_tab[2];

	if (!compute_struct_tab[0])
	{
		compute_struct_tab[0] = &set_comp_mandel;
	}
	return (&compute_struct_tab[fractal]);
}
