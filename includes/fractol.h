/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:23:03 by dapinto           #+#    #+#             */
/*   Updated: 2020/02/06 15:35:37 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "ft_printf.h"

typedef int			(*t_fractalizer)(void);
typedef void		(*t_compute)(int, int);
typedef int			(*t_event)(int);
typedef int			*(*t_palette)(void);

typedef struct	s_eve
{
	int			key;
	int			palet;
}				t_eve;

typedef struct		s_compute
{
	int		iter;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
}					t_comp;

typedef struct		s_fractol
{
	void		*mlx_server_ptr;
	void		*mlx_img_ptr;
	void		*mlx_win;
	int			*img_tab;
	int			endian;
	int			bpp;
	int			size_line;
	int			requested_fractal;
	int			max_iteration;
	int			zoom;
	t_eve		eve;
	t_comp		var;
	double		trans_x;
	double		trans_y;
	double		x1;
	double		y1;
	t_fractalizer	*fractal_type;
}					t_fractol;

char		**fractal_list(void);
int			get_arguments(int argc, char **argv);

t_fractol	*fetchenv(void);

int			do_nothing(int k);
int			ft_cleanclose(int k);
int			ft_translate(int k);
int			event_manager(int k);
int			mouse_mvt(int x, int y);
int			mouse_zm(int key, int x, int y);

int			*colour_tab(int palet);
void		clear_image(void);

int			julia(void);
int			mandelbrot(void);

void		draw(t_fractalizer *f, int fractal);

void		initialize_variables(int fractal_type);
t_compute	*set_compute_struct(int fractal);


#endif
