/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:10:59 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/07 11:16:43 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		**fractal_list(void)
{
	static char *list[4];

	if (!list[0])
	{
		list[0] = "mandelbrot";
		list[1] = "julia";
		list[2] = "burningship";
		list[3] = "mandelbrotflower";
	}
	return (list);
}

t_fractol	*fetchenv(void)
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
		fractol->eve.lock = 1;
	}
	return (fractol);
}

void		initialize_variables(int fractal)
{
	t_fractol	*frac;

	frac = fetchenv();
	frac->x1 = set_x1(fractal);
	frac->y1 = set_y1(fractal);
	if (fractal == 1)
	{
		frac->julia_r = frac->x1;
		frac->julia_i = frac->y1;
	}
	frac->max_iteration = set_maxiter(fractal);
	frac->zm = set_zoom(fractal);
	frac->trans_x = set_trans_x(fractal);
	frac->trans_y = set_trans_y(fractal);
}
