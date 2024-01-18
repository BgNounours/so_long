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
	new->fDir = c;
	new->next = NULL;
	return (new);
}

int	nbr_of_farmer(t_farmer farm)
{
	t_farmer	*tmp;
	int			i;

	tmp = farm;
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
			if (d->map[y][x] == 'v' || d->map[y][x] == 'v'
				|| d->map[y][x] == 'v' || d->map[y][x] == 'v')
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
