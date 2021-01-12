/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_palettes_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:31:27 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/12 13:36:37 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*alberage(void)
{
	static int colour_array[16];

	if (!colour_array[0])
	{
		colour_array[0] = 0xff6600;
		colour_array[1] = 0xff5825;
		colour_array[2] = 0xff493b;
		colour_array[3] = 0xff3a4f;
		colour_array[4] = 0xff2c62;
		colour_array[5] = 0xff2075;
		colour_array[6] = 0xff1b88;
		colour_array[7] = 0xff209b;
		colour_array[8] = 0xf92cad;
		colour_array[9] = 0xeb39be;
		colour_array[10] = 0xd946ce;
		colour_array[11] = 0xc452dc;
		colour_array[12] = 0xab5de9;
		colour_array[13] = 0x8c66f3;
		colour_array[14] = 0x656ffa;
		colour_array[15] = 0x1b76ff;
	}
	return (colour_array);
}