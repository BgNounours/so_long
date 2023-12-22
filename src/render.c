/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:16:31 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/21 13:04:03 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_img(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, img, 60 * x, 60 * y);
}

int	render_background(t_data *d)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (d->map[y] != NULL)
	{
		while (d->map[y][i] != '\0')
		{
			if (d->map[y][i] == '1')
				print_img(d, d->img.wall, i, y);
			if (d->map[y][i] == '0')
				print_img(d, d->img.floor, i, y);
			if (d->map[y][i] == 'E')
				print_img(d, d->img.exit, i, y);
			if (d->map[y][i] == 'C')
				print_img(d, d->img.collec, i, y);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

void	put_move(t_data *d)
{
	write(1, "Movement: ", 10);
	ft_putnbr(d->nb_move);
	write(1, "\n", 1);
}

void	draw(t_data *d)
{
	render_background(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.cow, d->posx, d->posy);
}

int	key_pressed(int keycode, t_data *d)
{
	if (keycode == KEY_ESCAPE)
		end(d);
	if (keycode == KEY_W)
	{
		d = move_up(d);
	}
	if (keycode == KEY_S)
	{
		d = move_down(d);
	}
	if (keycode == KEY_A)
	{
		d = move_left(d);
	}
	if (keycode == KEY_D)
	{
		d = move_right(d);
	}
	draw(d);
	return (0);
}
