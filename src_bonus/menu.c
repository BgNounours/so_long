/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:40:30 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/09 11:37:12 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	end_menu(t_data *d)
{
	mlx_loop_end(d->mlx);
	mlx_destroy_image(d->mlx, d->img.menu);
	mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	exit(0);
	return (0);
}

static int	quit_menu(int keycode, t_data *d)
{
	if (keycode != 0)
	{
		mlx_loop_end(d->mlx);
		mlx_destroy_image(d->mlx, d->img.menu);
		mlx_destroy_window(d->mlx, d->win);
		if (d->mlx)
			mlx_destroy_display(d->mlx);
		free(d->mlx);
		game(d);
	}
	return (0);
}

void	menu(t_data *d)
{
	int	x;
	int	y;

	x = 1440;
	y = 800;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 1440, 800, "game over :(");
	d->img.menu = mlx_xpm_file_to_image(d->mlx, "img/go.xpm", &x, &y);
	mlx_put_image_to_window(d->mlx, d->win, d->img.menu, 0, 0);
	mlx_key_hook(d->win, &quit_menu, d);
	mlx_hook(d->win, 17, 0L, &end_menu, d);
	mlx_loop(d->mlx);
}
