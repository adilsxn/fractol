/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:04:13 by acuva-nu          #+#    #+#             */
/*   Updated: 2023/06/19 12:04:13 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fl *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		free(f->mlx);
		err_out("ERROR: initiating MLX\n");
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win)
	{
		free(f->win);
		err_out("ERROR: creating a window\n");
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		err_out("ERROR: creating an image\n");
	f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->endian));
	if (!f->addr)
		err_out("ERROR: obtaining image address\n");
}

double	ft_atof(char *s)
{
	double	res;
	double	dec;
	char	*ptr;

	res = 0.0;
	dec = 0.1;
	res += ft_atoi(s);
	ptr = ft_strchr(s, '.');
	ptr++;
	while (ptr && ft_isdigit(*ptr))
	{
		res += ((*ptr - '0') * dec);
		dec *= 0.1;
		ptr++;
	}
	return (res);
}

void	get_julia(char **av, int ac, t_fl *f)
{
	f->f = &julia;
	if (ac == 2)
	{
		f->k.r = -0.715;
		f->k.i = 0.27015;
	}
	else if (ac == 3)
		err_out(MSG);
	else if (!ft_strchr(av[2], '.' ) || !ft_strchr(av[3], '.'))
		err_out(MSG);
	else
	{
		f->k.r = ft_atof(av[2]);
		f->k.i = ft_atof(av[3]);
	}
}

void	set_args(t_fl *f, char **av, int ac)
{
	if (ac < 2)
	{
		ft_printf("Please give me more arguments\n");
		err_out(MSG);
	}
	else if (ft_strequ(av[1], "m"))
		f->f = &mandelbrot;
	else if (ft_strequ(av[1], "j"))
		get_julia(av, ac, f);
	else if (ft_strequ(av[1], "b"))
		f->f = &burning;
	else if (ft_strequ(av[1], "t"))
		f->f = &tricorn;
	else
	{
		ft_printf("We don't have the '%s' fractal\n", av[1]);
		err_out(MSG);
	}
	f->movex = 0;
	f->movey = 0;
	f->zoom = 2;
	f->max_iter = 30;
	setup_color(f);
}

int	main(int ac, char *av[])
{
	t_fl	f;

	set_args(&f, av, ac);
	init_mlx(&f);
	draw(&f);
	mlx_hook(f.win, 17, 1L << 17, &au_revoir, &f);
	mlx_hook(f.win, KeyPress, KeyPressMask, &key_event, &f);
	mlx_mouse_hook(f.win, &mouse_event, &f);
	mlx_loop(f.mlx);
	return (0);
}
