/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:10:59 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/08 17:31:52 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char				**fractal_list(void)
{
	static char *list[3];

	if (!list[0])
	{
		list[0] = "mandelbrot";
		list[1] = "julia";
	}
	return (list);
}

void				initialize_variables(void)
{
	t_fractol *frac;

	frac = fetchenv();
	/*
	frac->x1 = set_x1(fractal);
	frac->x2 = set_x2(fractal);
	frac->y1 = set_y1(fractal);
	frac->y2 = set_y2(fractal);
	frac->max_iteration = set_maxiter(fractal);
	frac->zoom = set_zoom(fractal);
	*/
	frac->x1 = -2.1;
	frac->x2 = 0.6;
	frac->y1 = -1.2;
	frac->y2 = 1.2;
	frac->max_iteration = 50;
	frac->zoom = 300;
}

t_fractol			*fetchenv(void)
{
	static t_fractol *fractol = NULL;

	if (fractol == NULL)
	{
		if (!(fractol = ft_memalloc(sizeof(t_fractol))))
			return (NULL);
		fractol->mlx_server_ptr = mlx_init();
		fractol->mlx_img_ptr = mlx_new_image(fractol->mlx_server_ptr,\
				WIDTH, HEIGHT);
		fractol->img_tab = (int *)mlx_get_data_addr(fractol->mlx_img_ptr,
				&fractol->bpp, &fractol->size_line, &fractol->endian);
		fractol->mlx_win = mlx_new_window(fractol->mlx_server_ptr, WIDTH,
				HEIGHT, "Fract'ol");
		ft_bzero(&fractol->eve, sizeof(t_eve));
		ft_bzero(&fractol->var, sizeof(t_comp));
	}
	return (fractol);
}
