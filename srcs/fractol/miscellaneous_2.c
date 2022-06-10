/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/12 14:35:06 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractalizer		*fractal_holder(int fractal)
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

static void			menudisplay_sets(void)
{
	t_fractol *f;

	f = fetchenv();
	if (f->requested_fractal == 0)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 100,
			0xffffff, "Current set   : Mandelbrot");
	else if (f->requested_fractal == 1)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 100,
			0xffffff, "Current set   : Julia");
	else if (f->requested_fractal == 2)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 100,
			0xffffff, "Current set   : Burning Ship");
	else if (f->requested_fractal == 3)
		mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 100,
			0xffffff, "Current set   : Mandelbrot Flower");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 125,
		0xffffff, "Change set    : 0 to 3 on Numpad");
}

void				menudisplay(void)
{
	t_fractol *f;

	f = fetchenv();
	menudisplay_sets();
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 150, 0xffffff,
		"Lock ON / OFF : Space bar");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 175, 0xffffff,
		"Colour change : C");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 200, 0xffffff,
		"Move Fractal  : UP/DOWN/LEFT/RIGHT arrows");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 225, 0xffffff,
		"Zoom on coord : Left Mouse Button");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 250, 0xffffff,
		"Default Zoom  : Mouse Wheel");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 275, 0xffffff,
		"Reset         : HOME");
	mlx_string_put(f->mlx_server_ptr, f->mlx_win, 15, 300, 0xffffff,
		"Close window  : ESC or RED CROSS");
}

void				usage(void)
{
	ft_printf("USAGE: ./[fractol || Fractol_linux] [Fractal_Name] [--help ||");
	ft_printf(" --h] [--list || --l]\n\n");
	ft_printf("\t[fractol || Fractol_linux]:\n\t\tBinary for Fract'ol.\n\t\t");
	ft_printf("To ensure that the project is compilable on MacOS as well as ");
	ft_printf("Linux, the Makefile outputs two different executables.\n\t\t");
	ft_printf("By default, it will link the project for it to work on Linux.");
	ft_printf("\n\t\tElse, if the command \"make macdo\" is entered, the pro");
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

void				print_fractal_list(void)
{
	ft_printf("Here is the list of all available fractals to display:\n\t");
	ft_printf("1. Mandelbrot.\n\t2. Julia.\n\t3. Burningship\n\t4. Mandelbro");
	ft_printf("tflower\n");
}
