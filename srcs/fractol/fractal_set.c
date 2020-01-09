/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:28:29 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/09 16:16:27 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_comp_mandel(int x, int y)
{
	t_fractol *f;

	f = fetchenv();
	ft_bzero(&f->var, sizeof(t_comp));
	f->var.c_r = (double)x / f->zoom + f->x1;
	f->var.c_i = (double)y / f->zoom + f->y1;
}

