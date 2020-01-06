/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/06 17:21:28 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:20:41 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 15:13:40 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		usage(void)
{
	ft_printf("USAGE: ./[fractol || Fractol_linux] [Fractal_Name] [--help ||");
	ft_printf(" --h] [--list || --l]\n");
	ft_printf("\t[fractol || Fractol_linux]:\n\t\tBinary for Fract'ol.\n\t\t");
	ft_printf("To ensure that the project is compilable on MacOS as well as ");
	ft_printf("Linux, the Makefile outputs two different executables.\n\t\t");
	ft_printf("By default, it will link the project for it to work on MacOS.");
	ft_printf("\n\t\tElse, if the command \"make linux\" is entered, the pro");
	ft_printf("ject will be linked for it work on linux, given X11 library i");
	ft_printf("s installed.\n\t\tArgument hierarchy goes from top to low: ");
	ft_printf("[Fractal_Name] > [--h] > [--l]\n\t\t[fra");
	ft_printf("ctol] will only accept from one to the total number of availa");
	ft_printf("ble options number of arguments.\n\t\tSee below for more info");
	ft_printf("rmation.\n\n\t[Fractal_Name]:\n\t\tThe project supports a giv");
	ft_printf("en set of fractal ensembles.\n\t\tYou can find a list of th");
	ft_printf("eir names by using the [--list] option.\n\n");
	ft_printf("OPTIONS: Options may be placed in whichever order. The progra");
	ft_printf("m is not case sensitive regarding fractal names. Unknown op");
	ft_printf("tions will be ignored. Lack of known options will display usa");
	ft_printf("ge.\n\t[--help] or [--h]:\n\t\tDisplays usage.\n\n\t[--list] ");
	ft_printf("or [--l]:\n\t\tDisplays the list of supported fractals.\n");
}

static void		print_fractal_list(void)
{
	ft_printf("Here is the list of all available fractals to display:\n\t");
	ft_printf("1. Julia.\n\t2. Mandelbrot.\n");
}

static int		ft_fractol(int fract)
{
	t_fractol *fractol;

	fractol = fetchenv();
	(void)fract;
	//fractol algo with ptr to function index fract
	mlx_hook(fractol->mlx_win, 2, 0, &event_manager, &fractol);
	mlx_hook(fractol->mlx_win, 17, 0, &ft_cleanclose, &fractol);
	mlx_loop(fractol->mlx_server_ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	t_fractol	*fractol;
	int			fractal;

	if ((fractal = get_arguments(argc, argv)) < 0)
	{
		if (fractal == -1)
			usage();
		else if (fractal == -2)
			print_fractal_list();
		return (fractal);
	}
	fractol = fetchenv();
	ft_fractol(fractal);
	return (0);
}
