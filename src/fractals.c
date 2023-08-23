/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:34:46 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/21 11:34:46 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_cx c, t_fl f)
{
	int		i;
	t_cx	z;

	i = -1.0;
	z = (t_cx){0.0, 0.0};
	while (++i < f.max_iter && (pow(z.r, 2.0) + pow(z.i, 2.0)) < 4)
	{
		z = (t_cx){pow(z.r, 2.0) - pow(z.i, 2.0) + c.r, 2.0 * z.r * z.i + c.i};
	}
	return (i - log2(log2(pow(z.r, 2.0) + pow(z.i, 2.0))) + 4.0);
}

double	julia(t_cx z, t_fl f)
{
	int	i;

	i = -1.0;
	while (++i < f.max_iter && (pow(z.r, 2.0) + pow(z.i, 2.0)) < 4)
	{
		z = (t_cx){pow(z.r, 2.0) - pow(z.i, 2.0) + f.k.r, 2.0 * z.r * z.i
			+ f.k.i};
	}
	return (i - log2(log2(pow(z.r, 2.0) + pow(z.i, 2.0))) + 4.0);
}

double	burning(t_cx c, t_fl f)
{
	int		i;
	t_cx	z;

	i = -1.0;
	z = c;
	while (++i < f.max_iter && (pow(z.r, 2.0) + pow(z.i, 2.0)) < 4)
	{
		z = (t_cx){pow(z.r, 2.0) - pow(z.i, 2.0) + c.r, fabs(2.0 * z.r * z.i)
			+ c.i};
	}
	return (i - log2(log2(pow(z.r, 2.0) + pow(z.i, 2.0))) + 4.0);
}

double	tricorn(t_cx c, t_fl f)
{
	int		i;
	t_cx	z;

	i = -1.0;
	z = c;
	while (++i < f.max_iter && (pow(z.r, 2.0) + pow(z.i, 2.0)) < 4)
	{
		z = (t_cx){pow(z.r, 2.0) - pow(z.i, 2.0) + c.r, -2.0 * z.r * z.i + c.i};
	}
	return (i - log2(log2(pow(z.r, 2.0) + pow(z.i, 2.0))) + 4.0);
}
