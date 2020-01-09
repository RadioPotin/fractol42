/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/09 17:27:33 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		*color_tab(void)
{
	static int color_array[16];

	if (!color_array[0])
	{
		color_array[0] = 0xffff7d ;
		color_array[1] = 0xffee7d;
		color_array[2] = 0xffdf7e;
		color_array[3] = 0xffcf7e;
		color_array[4] = 0xffbf7e;
		color_array[5] = 0xffaf7e;
		color_array[6] = 0xff9f7e;
		color_array[7] = 0xff8f7f;
		color_array[8] = 0xfe7f7f;
		color_array[9] = 0xee6f7f;
		color_array[10] = 0xde5f7f;
		color_array[11] = 0xce4f7f;
		color_array[12] = 0xbe3f7f;
		color_array[13] = 0xae2f7f;
		color_array[14] = 0x9d1f7f;
		color_array[15] = 0x8d0e7f;
	}
	return (color_array);
}

void			trigger_px(double x, double y)
{
	t_fractol	*f;
	long		i;
	int			*color_table;

	f = fetchenv();
	color_table = color_tab();
	i = 0 + y * WIDTH + x;
	if (x >= 0 && f->var.iter < f->max_iteration)
		f->img_tab[i] = color_table[f->var.iter % 16];
	else
		f->img_tab[i] = 0;
}

void			usage(void)
{
	ft_printf("USAGE: ./[fractol || Fractol_linux] [Fractal_Name] [--help ||");
	ft_printf(" --h] [--list || --l]\n\n");
	ft_printf("\t[fractol || Fractol_linux]:\n\t\tBinary for Fract'ol.\n\t\t");
	ft_printf("To ensure that the project is compilable on MacOS as well as ");
	ft_printf("Linux, the Makefile outputs two different executables.\n\t\t");
	ft_printf("By default, it will link the project for it to work on MacOS.");
	ft_printf("\n\t\tElse, if the command \"make linux\" is entered, the pro");
	ft_printf("ject will be linked for it work on linux, given X11 library i");
	ft_printf("s installed.\n\t\tArgument hierarchy goes from top to low: ");
	ft_printf("[Fractal_Name] > [--h] > [--l]\n\n\t");
	ft_printf("[Fractal_Name]:\n\t\tThe project supports a given set of frac");
	ft_printf("tal ensembles.\n\t\tYou can find a list of their names by usi");
	ft_printf("ng the [--list] option.\n\n");
	ft_printf("OPTIONS: Options may be placed in whichever order. The progra");
	ft_printf("m is not case sensitive regarding fractal names. Unknown opti");
	ft_printf("ons will be ignored. Lack of known options will display usage");
	ft_printf(".\n\n\t[--help] or [--h]:\n\t\tDisplays usage.\n\n\t[--list] ");
	ft_printf("or [--l]:\n\t\tDisplays the list of supported fractals.\n");
}

void			print_fractal_list(void)
{
	ft_printf("Here is the list of all available fractals to display:\n\t");
	ft_printf("1. Julia.\n\t2. Mandelbrot.\n");
}
