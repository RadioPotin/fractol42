/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:20:41 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 13:25:15 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_fractol(int fract)
{
	t_fractol *fractol;

	fractol = fetchenv();
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

	fractol = fetchenv();
	if ((fractal = get_arguments(argc, argv)) <= 0)
	{
		//usage
		ft_cleanclose();
	}
	ft_fractol(fractal);
	return (0);
}
