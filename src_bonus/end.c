/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:40:30 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/09 11:37:12 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	game_over(t_data *d)
{
	int	x;
	int	y;

	x = 1440;
	y = 800;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 1440, 800, "game over :(");
	d->img.menu = mlx_xpm_file_to_image(d->mlx, "img/go.xpm", &x, &y);
	mlx_put_image_to_window(d->mlx, d->win, d->img.menu, 0, 0);
	mlx_key_hook(d->win, &end_game, d);
	mlx_hook(d->win, 17, 0L, &end_game, d);
	mlx_loop(d->mlx);
}

void	check_gameover(t_data *d)
{
	t_farmer	*tmp;

	tmp = d->farm->next;
	while (tmp != NULL)
	{
		if (d->posx == tmp->posx && d->posy == tmp->posy)
		{
			mlx_destroy_window(d->mlx, d->win);
			free_img(d);
			mlx_loop_end(d->mlx);
			if (d->mlx)
				mlx_destroy_display(d->mlx);
			free(d->mlx);
			game_over(d);
		}
		tmp = tmp->next;
	}
}

static void	f_win(t_data *d)
{
	int	x;
	int	y;

	x = 1440;
	y = 800;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 1440, 800, "Good Game :)");
	d->img.menu = mlx_xpm_file_to_image(d->mlx, "img/gg.xpm", &x, &y);
	mlx_put_image_to_window(d->mlx, d->win, d->img.menu, 0, 0);
	mlx_key_hook(d->win, &end_game, d);
	mlx_hook(d->win, 17, 0L, &end_game, d);
	mlx_loop(d->mlx);
}

void	win(t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	free_img(d);
	mlx_loop_end(d->mlx);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	f_win(d);
}
