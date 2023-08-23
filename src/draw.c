/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:44:51 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/22 15:44:51 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_img(t_fl *f, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	*(int *)&f->addr[(y * f->size) + (x * (f->bpp / 8))] = color;
}

void	draw(t_fl *f)
{
	int		x;
	int		y;
	double	iter;
	t_cx	pixel;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			pixel.r = (((x - WIDTH / 2) / f->zoom) + f->movex) / 200;
			pixel.i = (((HEIGHT / 2 - y) / f->zoom) + f->movey) / 200;
			iter = f->f(pixel, *f);
			put_pixel_img(f, x, y, get_color(f, iter));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
