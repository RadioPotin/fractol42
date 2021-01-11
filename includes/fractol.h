/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <dapinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:23:03 by dapinto           #+#    #+#             */
/*   Updated: 2021/01/11 11:03:48 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
# define THREADS 8
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "ft_printf.h"

typedef int			(*t_fractalizer)(void);
typedef void		(*t_compute)(int, int);
typedef int			(*t_event)(int);
typedef int			*(*t_palette)(void);

typedef struct	s_eve
{
	int			key;
	int			palet;
	int			lock;
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
	void			*mlx_server_ptr;
	void			*mlx_img_ptr;
	void			*mlx_win;
	int				*img_tab;
	int				endian;
	int				bpp;
	int				size_line;
	int				requested_fractal;
	int				max_iteration;
	int				zm;
	t_eve			eve;
	t_comp			var;
	double			trans_x;
	double			trans_y;
	double			x1;
	double			y1;
	double			julia_r;
	double			julia_i;
	t_fractalizer	*fractal_type;
	t_compute 		*fractal_compute;
}					t_fractol;

typedef struct		s_thread
{
	int				id;
	int 			y_limit;
	t_fractol		current_env;
}					t_thread;

/* Miscellaneous features */

char			**fractal_list(void);
int				get_arguments(int argc, char **argv);
void			usage(void);
void			print_fractal_list(void);

/* Environment */

t_fractol		*fetchenv(void);

/* Events and window details */

int				do_nothing(int k);
int				mouse_zm(int key, int x, int y);
int				mouse_mvt(int x, int y);
int				event_manager(int k);
int				ft_cleanclose(int k);
int				ft_translate(int k);
int				ft_switch(int k);
int				switch_palette(int k);
int				ft_reset(int k);
int				lockmvt(int k);
void			clear_image(void);
int				*colour_tab(int palet);
void            menudisplay(void);

void			draw(void);

/* Fractals */

t_fractalizer	*fractal_holder(int fractal);
int				julia(void);
int				mandelbrot(void);
int				burningship(void);
int				mandelbrot_flower(void);

/* Fractal variables init */

void			initialize_variables(int fractal_type);
double			set_x1(int fractal);
double			set_y1(int fractal);
int				set_maxiter(int fractal);
int				set_zoom(int fractal);
double			set_trans_y(int fractal);
double			set_trans_x(int fractal);

/* Computation functions */

t_compute		*set_compute_struct(int fractal);
void			set_comp_mandel(int x, int y);
void			set_comp_julia(int x, int y);
void			set_comp_burningship(int x, int y);

#endif
