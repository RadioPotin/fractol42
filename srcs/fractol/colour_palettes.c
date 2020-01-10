/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_palettes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:17:18 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/10 18:26:43 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*miko_vanille_fraise(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0xffff7d ;
		colour_array[1] = 0xffee7d;
		colour_array[2] = 0xffdf7e;
		colour_array[3] = 0xffcf7e;
		colour_array[4] = 0xffbf7e;
		colour_array[5] = 0xffaf7e;
		colour_array[6] = 0xff9f7e;
		colour_array[7] = 0xff8f7f;
		colour_array[8] = 0xfe7f7f;
		colour_array[9] = 0xee6f7f;
		colour_array[10] = 0xde5f7f;
		colour_array[11] = 0xce4f7f;
		colour_array[12] = 0xbe3f7f;
		colour_array[13] = 0xae2f7f;
		colour_array[14] = 0x9d1f7f;
		colour_array[15] = 0x8d0e7f;
	}
	return (colour_array);
}

int		*bryce_canyon(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0xff7f00;
		colour_array[1] = 0xfaa401;
		colour_array[2] = 0xf4661b;
		colour_array[3] = 0xef9b0f;
		colour_array[4] = 0xed7f10;
		colour_array[5] = 0xe67e30;
		colour_array[6] = 0xdf6d14;
		colour_array[7] = 0xcc5500;
		colour_array[8] = 0x77b5fe;
		colour_array[9] = 0x318ce7;
		colour_array[10] = 0x2c75ff;
		colour_array[11] = 0x1b019b;
		colour_array[12] = 0x1560bd;
		colour_array[13] = 0x1034a6;
		colour_array[14] = 0x0f9de8;
		colour_array[15] = 0x007fff;
	}
	return (colour_array);
}

int		*colour_tab(int palet)
{
	static t_palette colour_palettes[16];

	if (!colour_palettes[0])
	{
		colour_palettes[0] = &miko_vanille_fraise;
		colour_palettes[1] = &bryce_canyon;
	}
	return (colour_palettes[palet]());
}
