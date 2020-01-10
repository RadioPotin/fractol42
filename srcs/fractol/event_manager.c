/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:27:16 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/10 17:49:52 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_event	*fetchevent(void)
{
	static t_event	holder[160];
	int				i;

	if (!holder[53])
	{
		i = 0;
		while (i < 160)
			holder[i++] = &do_nothing;
		holder[53] = &ft_cleanclose;
		holder[123] = &ft_translate;
		holder[124] = &ft_translate;
		holder[125] = &ft_translate;
		holder[126] = &ft_translate;
	}
	return (holder);
}

static int	is_event(int k)
{
	if (k == 53 || k == 123 || k == 124 || k == 125 || k == 126)
		return (1);
	return (0);
}

int		event_manager(int k)
{
	t_fractol	*fractol;
	t_event		*event_holder;

	if (!is_event(k))
		return (0);
	fractol = fetchenv();
	event_holder = fetchevent();
	mlx_destroy_image(fractol->mlx_server_ptr, fractol->mlx_img_ptr);
	fractol->mlx_img_ptr = mlx_new_image(fractol->mlx_server_ptr,\
			WIDTH, HEIGHT);
	fractol->img_tab = (int *)mlx_get_data_addr(fractol->mlx_img_ptr,
			&fractol->bpp, &fractol->size_line, &fractol->endian);
	return (event_holder[k](k));
}
