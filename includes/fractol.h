/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:23:03 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/08 17:15:01 by dapinto          ###   ########.fr       */
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

typedef struct	s_eve
{
	int			key;
	int			state;
	int			event;
	int			trans_x;
	int			trans_y;
}				t_eve;

typedef struct		s_compute
{
	double	x;
	double	y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		iter;
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
	int			max_iteration;
	int			zoom;
	t_fractalizer	*fractal_type;
	t_eve		eve;
	t_comp		var;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
}					t_fractol;


t_fractol	*fetchenv(void);
void		trigger_px(double x, double y);
void		usage(void);
void		draw(t_fractalizer *f);
void		initialize_variables(void);
void		print_fractal_list(void);
int			get_arguments(int argc, char **argv);
char		**fractal_list(void);
int			event_manager(int k);
int			ft_cleanclose(void);
int			julia(void);
int			mandelbrot(void);


#endif
