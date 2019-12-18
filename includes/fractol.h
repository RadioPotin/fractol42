/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:23:03 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/18 12:38:05 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "ft_printf.h"

typedef struct	s_eve
{
	int			state;
	int			event;
}				t_eve;

typedef struct		s_fractol
{
	void		*mlx_server_ptr;
	void		*mlx_img_ptr;
	void		*mlx_win;
	int			*img_tab;
	int			endian;
	int			bpp;
	int			size_line;
	t_eve		eve;
}					t_fractol;

t_fractol	*fetchenv(void);
int			event_manager(int k);
int			ft_cleanclose(void);

#endif
