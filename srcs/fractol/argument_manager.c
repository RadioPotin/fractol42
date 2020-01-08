/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:21:25 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/08 17:13:02 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		look_up(int size, char **array, char *key)
{
	int i;

	i = 0;
	if (!ft_strchr(key, '-'))
		while (key[i] && (key[i] = ft_tolower(key[i])))
			i++;
	i = 0;
	while (array[i] && i < size)
	{
		if (!ft_strcmp(array[i], key))
			return (i);
		i++;
	}
	return (-1);
}

static int		fetch_fractal(int argc, char **argv)
{
	char	**f_list;
	int		i;
	int		j;

	i = 1;
	f_list = fractal_list();
	while (argv[i] && i < argc)
	{
		if (!ft_strchr(argv[i], '-'))
			if ((j = look_up(3, f_list, argv[i])) >= 0)
			{
			ft_printf("FRACTAL SELECTER = %d\n", j);
				return (j);
				}
		i++;
	}
	return (-1);
}

int		get_arguments(int argc, char **argv)
{
	int fractal;

	if ((fractal = fetch_fractal(argc, argv)) >= 0)
		return (fractal);
	else if (look_up(argc, argv, "--help") > 0
			|| look_up(argc, argv, "--h") > 0)
		return (-1);
	else if (look_up(argc, argv, "--list") > 0
			|| look_up(argc, argv, "--l") > 0)
		return (-2);
	return (-1);
}
