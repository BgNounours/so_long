/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:05:21 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/22 11:31:08 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	d->img.wall = mlx_xpm_file_to_image(d->mlx, "img/wall.xpm", &s, &s);
	d->img.floor = mlx_xpm_file_to_image(d->mlx, "img/flor.xpm", &s, &s);
	d->img.exit = mlx_xpm_file_to_image(d->mlx, "img/exit.xpm", &s, &s);
	d->img.collec = mlx_xpm_file_to_image(d->mlx, "img/colect.xpm", &s, &s);
	d->img.cow = mlx_xpm_file_to_image(d->mlx, "img/cow.xpm", &s, &s);
	return (d);
}

static void	game(t_data *d)
{
	d->width--;
	d->nb_move = 0;
	d->mlx = mlx_init();
	d = set_img(d);
	d->win = mlx_new_window(d->mlx, d->width * 60, d->height * 60, "so_long");
	render_background(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.cow, d->posx, d->posy);
	mlx_key_hook(d->win, &key_pressed, d);
	mlx_loop(d->mlx);
}

int	main(int ac, char **av)
{
	t_data	*d;

	if (ac != 2)
	{
		write(1, "Error, enter '.der' files!\n", 27);
		return (0);
	}
	if (wrong_file(av[1]) == 1)
	{
		write(1, "Error, enter '.der' files!\n", 27);
		return (0);
	}
	d = malloc(sizeof(t_data) * 1);
	d = get_map(d, av[1]);
	check_map(d);
	if (d->good_map == 0)
	{
		pre_end(d);
		write(1, "Error, invalid map!\n", 20);
		return (0);
	}
	game(d);
	end(d);
}
