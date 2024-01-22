/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:16:31 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/11 13:34:37 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_img(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, img, 60 * x, 60 * y);
}

static t_data	*render_norm(t_data *d, int i, int y)
{
	if (d->map[y][i] == '1')
		print_img(d, d->img.wall, i, y);
	if (d->map[y][i] == '0' || d->map[y][i] == 'D'
		|| d->map[y][i] == 'U' || d->map[y][i] == 'R'
		|| d->map[y][i] == 'L')
		print_img(d, d->img.floor, i, y);
	if (d->map[y][i] == 'E')
		print_img(d, d->img.exit[0], i, y);
	if (d->map[y][i] == 'C')
		print_img(d, d->img.collec[0], i, y);
	if (d->map[y][i] == 'c')
		print_img(d, d->img.collec[1], i, y);
	return (d);
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
			d = render_norm(d, i, y);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

void	draw(t_data *d)
{
	render_background(d);
	if (d->pdir == 'D')
		mlx_put_image_to_window(d->mlx, d->win, d->img.cow[0], d->posx,
			d->posy);
	if (d->pdir == 'U')
		mlx_put_image_to_window(d->mlx, d->win, d->img.cow[1], d->posx,
			d->posy);
	if (d->pdir == 'R')
		mlx_put_image_to_window(d->mlx, d->win, d->img.cow[2], d->posx,
			d->posy);
	if (d->pdir == 'L')
		mlx_put_image_to_window(d->mlx, d->win, d->img.cow[3], d->posx,
			d->posy);
	draw_farmer(d);
}

int	key_pressed(int keycode, t_data *d)
{
	if (keycode == KEY_ESCAPE)
	{
		end(d);
		exit(0);
	}
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
	render_farmer(d);
	draw(d);
	return (0);
}
