/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:49:34 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/19 13:49:34 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
		if (key == XK_u)
			unknown_color(f);
		if (key == XK_p)
			ayahuasca(f);
*/

int	au_revoir(t_fl *f)
{
	if (f)
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(EXIT_SUCCESS);
}

void	err_out(char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

int	mouse_event(int key, int x, int y, t_fl *f)
{
	if (key == 4 || key == 5)
		zoom(key, x - WIDTH / 2, HEIGHT / 2 - y, f);
	return (1);
}

int	key_event(int key, t_fl *f)
{
	if (key == XK_Escape)
		return (au_revoir(f));
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left
		|| key == XK_KP_Subtract || key == XK_KP_Add || key == '1' || key == '2'
		|| key == '3' || key == XK_p)
	{
		if (ft_strchr("1234", key))
			toggle_color(f, key);
		if (key == XK_Up)
			f->movey -= HEIGHT / (20 * f->zoom);
		if (key == XK_Down)
			f->movey += HEIGHT / (20 * f->zoom);
		if (key == XK_Right)
			f->movex += WIDTH / (20 * f->zoom);
		if (key == XK_Left)
			f->movex -= WIDTH / (20 * f->zoom);
		if (key == XK_KP_Subtract)
			f->max_iter -= 10;
		if (key == XK_KP_Add)
			f->max_iter += 10;
		if (key == XK_p)
			ayahuasca(f);
		draw(f);
	}
	return (1);
}

void	zoom(int key, int x, int y, t_fl *f)
{
	if (key == 4)
	{
		f->zoom *= 2;
		f->movex += x / f->zoom;
		f->movey += y / f->zoom;
	}
	if (key == 5)
		f->zoom /= 2;
	draw(f);
}
