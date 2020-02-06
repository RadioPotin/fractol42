/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/06 16:12:09 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				usage(void)
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

static void				print_fractal_list(void)
{
	ft_printf("Here is the list of all available fractals to display:\n\t");
	ft_printf("1. Mandelbrot.\n\t2. Julia.\n");
}

static t_fractalizer	*fractal_holder(int fractal)
{
	static t_fractalizer hold[9];

	if (!hold[0])
	{
		hold[0] = &mandelbrot;
		hold[1] = &julia;
		//hold[2] = &julia;
		//hold[3] = &julia;
	}
	return (&hold[fractal]);
}

static int				ft_fractol(int fractal)
{
	t_fractol		*fractol;

	fractol = fetchenv();
	fractol->requested_fractal = fractal;
	initialize_variables(fractal);
	fractol->fractal_type = fractal_holder(fractal);
	draw(fractol->fractal_type, fractal);

	mlx_hook(fractol->mlx_win, 2, 0, &event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 6, 0, &mouse_mvt, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, &ft_cleanclose, &fractol);
	mlx_loop_hook(fractol->mlx_server_ptr, mouse_mvt, &fractol);
	//mlx_mouse_hook(fractol->mlx_win, mouse_zm, fractol);

	mlx_loop(fractol->mlx_server_ptr);
	return (0);
}

int						main(int argc, char **argv)
{
	int			fractal;

	if ((fractal = get_arguments(argc, argv)) < 0)
	{
		if (fractal == -1)
			usage();
		else if (fractal == -2)
			print_fractal_list();
		return (fractal);
	}
	ft_fractol(fractal);
	return (0);
}
