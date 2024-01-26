/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:05:21 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/12 09:22:52 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	wrong_file(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i < 5)
		return (1);
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b')
		return (1);
	if (s[i - 4] != '.')
		return (1);
	return (0);
}

static t_data	*set_img(t_data *d)
{
	int	s;

	s = 60;
	d->img.collec = malloc(sizeof(void *) * 2);
	d->img.cow = malloc(sizeof(void *) * 4);
	d->img.exit = malloc(sizeof(void *) * 2);
	d->img.score = malloc(sizeof(void *) * 3);
	d->img.farm = malloc(sizeof(void *) * 4);
	d->img.wall = mlx_xpm_file_to_image(d->mlx, "img/wall.xpm", &s, &s);
	d->img.floor = mlx_xpm_file_to_image(d->mlx, "img/flor.xpm", &s, &s);
	d->img.exit[0] = mlx_xpm_file_to_image(d->mlx, "img/exit.xpm", &s, &s);
	d->img.exit[1] = mlx_xpm_file_to_image(d->mlx, "img/exitable.xpm", &s, &s);
	d->img.collec[0] = mlx_xpm_file_to_image(d->mlx, "img/colect.xpm", &s, &s);
	d->img.collec[1] = mlx_xpm_file_to_image(d->mlx, "img/kk.xpm", &s, &s);
	d->img.cow[0] = mlx_xpm_file_to_image(d->mlx, "img/p/pD.xpm", &s, &s);
	d->img.cow[1] = mlx_xpm_file_to_image(d->mlx, "img/p/pU.xpm", &s, &s);
	d->img.cow[2] = mlx_xpm_file_to_image(d->mlx, "img/p/pL.xpm", &s, &s);
	d->img.cow[3] = mlx_xpm_file_to_image(d->mlx, "img/p/pR.xpm", &s, &s);
	d->img.farm[0] = mlx_xpm_file_to_image(d->mlx, "img/f/fD.xpm", &s, &s);
	d->img.farm[1] = mlx_xpm_file_to_image(d->mlx, "img/f/fU.xpm", &s, &s);
	d->img.farm[2] = mlx_xpm_file_to_image(d->mlx, "img/f/fL.xpm", &s, &s);
	d->img.farm[3] = mlx_xpm_file_to_image(d->mlx, "img/f/fR.xpm", &s, &s);
	d = set_nbr_img(d);
	return (d);
}

void	game(t_data *d)
{
	d->width--;
	d->nb_move = 0;
	d->pdir = 'D';
	d->mlx = mlx_init();
	d = set_img(d);
	d->win = mlx_new_window(d->mlx, d->width * 60, d->height * 60, "so_long");
	render_background(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.cow[0], d->posx, d->posy);
	if (d->farm->next != NULL)
		draw_farmer(d);
	render_score(d, ft_itoa(d->nb_move));
	mlx_key_hook(d->win, &key_pressed, d);
	mlx_hook(d->win, 17, 0L, &end_exit, d);
	mlx_loop(d->mlx);
}

static int	nomap(void)
{
	write(1, "Error: No file found\n", 22);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*d;

	if (ac != 2)
	{
		write(1, "Error: Enter only one map file\n", 32);
		return (0);
	}
	if (wrong_file(av[1]) == 1)
	{
		write(1, "Error: Enter a '.ber' file\n", 27);
		return (0);
	}
	d = malloc(sizeof(t_data) * 1);
	d = get_map(d, av[1]);
	if (d == NULL)
		return (nomap());
	d = check_map(d);
	if (d->good_map == 0)
	{
		pre_end(d);
		write(1, "Error: Invalid map\n", 19);
		return (0);
	}
	game(d);
	end(d);
}
