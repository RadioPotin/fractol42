/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:15:06 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 16:20:58 by dapinto          ###   ########.fr       */
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
	ft_printf("\t[fractol || Fractol_linux]:\n\t\tBinary for Fractol project");
	ft_printf("\n\t\tTo ensure that the project is compilable on MacOS as we");
	ft_printf("ll as other distributions, the Makefile outputs two different");
	ft_printf(" executables.\n\t\tBy default, it will link the project for i");
	ft_printf("t to work on MacOS.\n\t\t");
	ft_printf("Else, if the command \"make linux\" is entered, ");
	ft_printf("the project will be linked in a way that ensures its function");
	ft_printf("ability on Linux distributions.\n\t\tArgument hierarchy goes ");
	ft_printf("from top to low: [Fractal_Name] > [--h] > [--l]\n\t\t[fra");
	ft_printf("ctol] will only accept from one to the total number of availa");
	ft_printf("ble options number of arguments.\n\t\tSee below for more info");
	ft_printf("rmation.\n\n\t[Fractal_Name]:\n\t\tThe project supports a giv");
	ft_printf("en set of fractal ensembles.\n\t\tYou can find a list of th");
	ft_printf("eir names by using the [--list] option.\n\n");
	ft_printf("OPTIONS: Options may be placed in whichever order. Unknown op");
	ft_printf("tions will be ignored. Lack of known options will display usa");
	ft_printf("ge.\n\t[--help] or [--h]:\n\t\tDisplays usage.\n\n\t[--list] ");
	ft_printf("or [--l]:\n\t\tDisplays the list of supported fractals. ");
	ft_printf("The program is not case sensitive regarding the names.\n");
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

	if ((fractal = get_arguments(argc, argv)) <= 0)
	{
		if (fractal == -1)
			usage();
		//Else
		//print fractal_list
		return (fractal);
	}
	fractol = fetchenv();
	ft_fractol(fractal);
	return (0);
}
