/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:28:29 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/12 10:48:43 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_comp_mandel(int x, int y, t_fractol *f, t_comp *comp)
{
	t_comp *var;

	var = comp;
	ft_bzero(var, sizeof(t_comp));
	var->c_r = (double)x / f->zm + f->x1 + f->trans_x;
	var->c_i = (double)y / f->zm + f->y1 + f->trans_y;
}

void		set_comp_julia(int x, int y, t_fractol *f, t_comp *comp)
{
	t_comp *var;

	var = comp;
	ft_bzero(var, sizeof(t_comp));
	var->z_r = (double)x / f->zm + f->x1 + f->trans_x;
	var->z_i = (double)y / f->zm + f->y1 + f->trans_y;
	var->c_r = f->julia_r;
	var->c_i = f->julia_i;
}

void		set_comp_burningship(int x, int y, t_fractol *f, t_comp *comp)
{
	t_comp *var;

	var = comp;
	ft_bzero(var, sizeof(t_comp));
	var->c_r = (double)x / f->zm + f->x1 + f->trans_x;
	var->c_i = (double)y / f->zm + f->y1 + f->trans_y;
}
