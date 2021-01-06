/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_palettes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:17:18 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/07 11:34:44 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*miko_vanille_fraise(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0xffff7d;
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
		colour_array[0] = 0x000303;
		colour_array[1] = 0x001817;
		colour_array[2] = 0x002624;
		colour_array[3] = 0x003530;
		colour_array[4] = 0x00443b;
		colour_array[5] = 0x005444;
		colour_array[6] = 0x00644c;
		colour_array[7] = 0x007552;
		colour_array[8] = 0x008656;
		colour_array[9] = 0x009758;
		colour_array[10] = 0x00a859;
		colour_array[11] = 0x00b957;
		colour_array[12] = 0x00cb53;
		colour_array[13] = 0x00dc4c;
		colour_array[14] = 0x00ee41;
		colour_array[15] = 0x2bff30;
	}
	return (colour_array);
}

int		*are_you_ogay(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0xC970A3;
		colour_array[1] = 0xED95BB;
		colour_array[2] = 0xF7B7D1;
		colour_array[3] = 0xB5A5D4;
		colour_array[4] = 0xA5BDDF;
		colour_array[5] = 0x6199C8;
		colour_array[6] = 0x49D3CD;
		colour_array[7] = 0x35DECE;
		colour_array[8] = 0x0CBDC7;
		colour_array[9] = 0x00A5C0;
		colour_array[10] = 0x2D9ABB;
		colour_array[11] = 0x3C249C;
		colour_array[12] = 0x832AD0;
		colour_array[13] = 0x482183;
		colour_array[14] = 0x542C8A;
		colour_array[15] = 0x7353A6;
	}
	return (colour_array);
}

int		*fire(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0x582a2a;
		colour_array[1] = 0x6a322e;
		colour_array[2] = 0x7b3b31;
		colour_array[3] = 0x8c4533;
		colour_array[4] = 0x9d5033;
		colour_array[5] = 0xad5b33;
		colour_array[6] = 0xbb6831;
		colour_array[7] = 0xc9762f;
		colour_array[8] = 0xd5842b;
		colour_array[9] = 0xdf9426;
		colour_array[10] = 0xe8a41f;
		colour_array[11] = 0xefb516;
		colour_array[12] = 0xf5c70a;
		colour_array[13] = 0xf8d900;
		colour_array[14] = 0xf9ec00;
		colour_array[15] = 0xf8ff00;
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
		colour_palettes[2] = &are_you_ogay;
		colour_palettes[3] = &fire;
	}
	return (colour_palettes[palet]());
}
