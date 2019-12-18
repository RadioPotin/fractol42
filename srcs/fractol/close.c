/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:12:22 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 12:33:25 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_cleanclose(void)
{
	t_fractol	*fractol;

	fractol = fetchenv();
	mlx_destroy_image(fractol->mlx_server_ptr, fractol->mlx_img_ptr);
	free(fractol);
	exit(0);
}
