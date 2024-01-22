/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farmer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:40:30 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/09 11:37:12 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_farmer	*new_farmer(int x, int y, char c)
{
	t_farmer	*new;

	new = malloc(sizeof(t_farmer));
	new->posx = x;
	new->posy = y;
	new->fdir = c;
	new->next = NULL;
	return (new);
}

int	nbr_of_farmer(t_farmer *farm)
{
	t_farmer	*tmp;
	int			i;

	tmp = NULL;
	tmp = farm;
	i = 0;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_data	*get_farmer(t_data *d)
{
	int			x;
	int			y;
	t_farmer	*tmp;

	x = 0;
	y = 0;
	tmp = d->farm;
	while (y < d->height)
	{
		while (x < d->width)
		{
			if (d->map[y][x] == 'D' || d->map[y][x] == 'U'
				|| d->map[y][x] == 'L' || d->map[y][x] == 'R')
			{
				tmp->next = new_farmer(x * 60, y * 60, d->map[y][x]);
				tmp = tmp->next;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (d);
}

void	draw_farmer(t_data *d)
{
	t_farmer	*tmp;

	tmp = d->farm->next;
	while (tmp != NULL)
	{
		if (tmp->fdir == 'D')
			mlx_put_image_to_window(d->mlx, d->win, d->img.farm[0], tmp->posx,
				tmp->posy);
		if (tmp->fdir == 'U')
			mlx_put_image_to_window(d->mlx, d->win, d->img.farm[0], tmp->posx,
				tmp->posy);
		if (tmp->fdir == 'L')
			mlx_put_image_to_window(d->mlx, d->win, d->img.farm[0], tmp->posx,
				tmp->posy);
		if (tmp->fdir == 'R')
			mlx_put_image_to_window(d->mlx, d->win, d->img.farm[0], tmp->posx,
				tmp->posy);
		tmp = tmp->next;
	}
}
