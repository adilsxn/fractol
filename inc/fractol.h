/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:26 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/21 11:27:26 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/*-------------------------------Constants--------------------------------*/
# define WIDTH 1280
# define HEIGHT 800
# define MSG "We have:\n m-> Mandelbrot\n t-> Tricorn \n b-> Burning Ship \n \
j-> Julia \t[please give me (float) Re + (float) Im starters]\n"

/*
 * Struct for 
 * a complex number
 * real & imaginary
 */
typedef struct s_cx
{
	double	r;
	double	i;
}			t_cx;

typedef struct s_color
{
	float	r_frq;
	float	g_frq;
	float	b_frq;
	float	r_ph;
	float	g_ph;
	float	b_ph;
}			t_color;

typedef struct s_fl
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
	double	movex;
	double	movey;
	double	zoom;
	int		max_iter;
	t_cx	k;
	char	palette;
	t_color	color;
	double	(*f)(t_cx, struct s_fl);
}			t_fl;

/*-------------------------Fractal functions---------------------*/
double		mandelbrot(t_cx c, t_fl f);
double		julia(t_cx z, t_fl f);
double		burning(t_cx c, t_fl f);
double		tricorn(t_cx c, t_fl f);
/*--------------------------Colors----------------------------*/
void		setup_color(t_fl *f);
void		toggle_color(t_fl *f, char key);
void		ayahuasca(t_fl *f);
int			get_color(t_fl *f, double iter);

/*-------------------------Rendering-------------------------*/
void		put_pixel_img(t_fl *f, int x, int y, int color);
t_cx		map(t_fl *f, int x, int y);
void		draw(t_fl *f);
void		zoom(int key, int x, int y, t_fl *f);
/*-------------------------Evensts--------------------------*/
int			key_event(int key, t_fl *f);
int			mouse_event(int key, int x, int y, t_fl *f);
int			esc_win(int key, t_fl *f);
/*-------------------------Utilities------------------------*/
void		err_out(char *msg);
void		init_mlx(t_fl *f);
int			au_revoir(t_fl *f);
void		set_args(t_fl *f, char **av, int ac);
#endif
