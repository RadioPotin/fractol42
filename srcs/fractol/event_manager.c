/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:27:16 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 12:53:00 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					event_manager(int k)
{
	t_fractol *fractol;

	fractol = fetchenv();
	mlx_destroy_image(fractol->mlx_server_ptr, fractol->mlx_img_ptr);
	fractol->mlx_img_ptr = mlx_new_image(fractol->mlx_server_ptr,\
			WIDTH, HEIGHT);
	fractol->img_tab = (int *)mlx_get_data_addr(fractol->mlx_img_ptr,
			&fractol->bpp, &fractol->size_line, &fractol->endian);
	if (k == 53)
		ft_cleanclose();
	return (0);
}
