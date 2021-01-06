/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:28:29 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/25 10:49:56 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_comp_mandel(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	ft_bzero(&f->var, sizeof(t_comp));
	f->var.c_r = (double)x / f->zm + f->x1 + f->trans_x;
	f->var.c_i = (double)y / f->zm + f->y1 + f->trans_y;
}

void		set_comp_julia(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	ft_bzero(&f->var, sizeof(t_comp));
	f->var.z_r = (double)x / f->zm + f->x1 + f->trans_x;
	f->var.z_i = (double)y / f->zm + f->y1 + f->trans_y;
	f->var.c_r = f->julia_r;
	f->var.c_i = f->julia_i;
}

void		set_comp_burningship(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	ft_bzero(&f->var, sizeof(t_comp));
	f->var.c_r = (double)x / f->zm + f->x1 + f->trans_x;
	f->var.c_i = (double)y / f->zm + f->y1 + f->trans_y;
}