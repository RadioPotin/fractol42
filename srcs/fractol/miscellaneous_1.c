/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:20:51 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/13 11:39:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					*colour_tab(int palet)
{
	static t_palette colour_palettes[16];

	if (!colour_palettes[0])
	{
		colour_palettes[0] = &miko_vanille_fraise;
		colour_palettes[1] = &bryce_canyon;
		colour_palettes[2] = &are_you_ogay;
		colour_palettes[3] = &fire;
		colour_palettes[4] = &alberage;
		colour_palettes[5] = &yunowork;
	}
	return (colour_palettes[palet]());
}

static void			trigger_px(double x, double y, t_comp *var)
{
	t_fractol	*f;
	long		i;
	int			*colour_table;

	f = fetchenv();
	colour_table = colour_tab(f->eve.palet);
	i = 0 + y * WIDTH + x;
	if (x >= 0 && var->iter < f->max_iteration)
		f->img_tab[i] = colour_table[var->iter % 16];
	else
		f->img_tab[i] = 0;
}

void				*proceed(void *arg)
{
	int			max_iteration;
	int			x;
	int			y;
	t_thread	*thread;
	t_comp		var;

	thread = (t_thread *)arg;
	y = thread->y;
	var = thread->var;
	max_iteration = thread->env->max_iteration;
	while (y < thread->top)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*thread->env->fractal_compute)(x, y, thread->env, &(var));
			(*thread->env->fractal_type)(max_iteration, &(var));
			trigger_px((double)x, (double)y, &(var));
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void				draw(void)
{
	int				i;
	t_fractol		*fractol;
	t_thread		thread[THREADS];

	i = 0;
	fractol = fetchenv();
	while (i < THREADS)
	{
		thread[i].n = i;
		thread[i].env = fractol;
		thread[i].top = (i + 1) * HEIGHT / THREADS;
		thread[i].y = i * HEIGHT / THREADS;
		pthread_create(&(thread[i].id), NULL, &proceed, (void *)&thread[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thread[i++].id, NULL);
	mlx_put_image_to_window(fractol->mlx_server_ptr, fractol->mlx_win,
			fractol->mlx_img_ptr, 0, 0);
}
