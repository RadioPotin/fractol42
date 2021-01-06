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

t_compute		*set_compute_struct(int fractal)
{
	static t_compute compute_struct_tab[4];

	if (!compute_struct_tab[0])
	{
		compute_struct_tab[0] = &set_comp_mandel;
		compute_struct_tab[1] = &set_comp_julia;
		compute_struct_tab[2] = &set_comp_burningship;
		compute_struct_tab[3] = &set_comp_mandel;
	}
	return (&compute_struct_tab[fractal]);
}