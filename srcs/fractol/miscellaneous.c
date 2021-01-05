/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/25 12:32:12 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				clear_image(void)
{
	t_fractol	*f;
	int			i;

	i = 0;
	f = fetchenv();
	while (i < WIDTH * HEIGHT)
	{
		if (f->img_tab[i] != 0)
			f->img_tab[i] = 0;
		i++;
	}
}

void				usage(void)
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

void				print_fractal_list(void)
{
	ft_printf("Here is the list of all available fractals to display:\n\t");
	ft_printf("1. Mandelbrot.\n\t2. Julia.\n\t3. Burningship\n");
}

static void			trigger_px(double x, double y)
{
	t_fractol	*f;
	long		i;
	int			*colour_table;

	f = fetchenv();
	colour_table = colour_tab(1);
	i = 0 + y * WIDTH + x;
	if (x >= 0 && f->var.iter < f->max_iteration)
		f->img_tab[i] = colour_table[f->var.iter % 16];
	else
		f->img_tab[i] = 0;
}

void				draw(t_fractalizer *fractal_type, int fractal)
{
	int			x;
	int			y;
	t_fractol	*fractol;
	t_compute	*fractal_compute;

	y = 0;
	fractol = fetchenv();
	fractal_compute = set_compute_struct(fractal);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*fractal_compute)(x, y);
			(*fractal_type)();
			trigger_px(x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win,
			fractol->mlx_img_ptr, 0, 0);
}
