/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:04:17 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/07/17 14:04:17 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*Based heavily on tutorial found on:
 * https://www.paridebroggi.com/blogpost/2015/05/06/fractal-continuous-coloring/
 * and
 * https://krazydad.com/tutorials/makecolors.php */

void	setup_color(t_fl *f)
{
	f->color.r_frq = 0.33;
	f->color.g_frq = 0.33;
	f->color.b_frq = 0.33;
	f->color.r_ph = 0.0;
	f->color.g_ph = (2 * M_PI / 3);
	f->color.b_ph = (4 * M_PI / 3);
	f->palette = 'a';
}

void	toggle_color(t_fl *f, char key)
{
	if (key == '1')
	{
		f->color.r_frq = 0.33;
		f->color.g_frq = 0.33;
		f->color.b_frq = 0.00;
	}
	if (key == '2')
	{
		f->color.r_frq = 0.33;
		f->color.g_frq = 0.00;
		f->color.b_frq = 0.33;
	}
	if (key == '3')
	{
		f->color.r_frq = 0.00;
		f->color.g_frq = 0.33;
		f->color.b_frq = 0.33;
	}
}

void	ayahuasca(t_fl *f)
{
	f->color.r_ph = rand() % 20;
	f->color.g_ph = rand() % 20;
	f->color.b_ph = rand() % 20;
}

int	get_color(t_fl *f, double iter)
{
	int		tmp[3];
	t_color	it;

	it = f->color;
	tmp[0] = sin(fmod(it.r_frq * iter + it.r_ph, 2 * M_PI)) * 128 + 127;
	tmp[1] = sin(fmod(it.g_frq * iter + it.g_ph, 2 * M_PI)) * 128 + 127;
	tmp[2] = sin(fmod(it.b_frq * iter + it.b_ph, 2 * M_PI)) * 128 + 127;
	return (tmp[0] << 16 | tmp[1] << 8 | tmp[2]);
}
