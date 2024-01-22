/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_farmer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:47:02 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/21 13:05:11 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_farmer	*move_farmer_left(t_farmer *farm, char **map)
{
	if (map[farm->posy / 60][(farm->posx / 60) + 1] == '1'
		|| map[farm->posy / 60][(farm->posx / 60) + 1] == 'E')
	{
		farm->fdir = 'R';
		return (farm);
	}
	farm->posx += 60;
	return (farm);
}

t_farmer	*move_farmer_right(t_farmer *farm, char **map)
{
	if (map[farm->posy / 60][(farm->posx / 60) - 1] == '1'
		|| map[farm->posy / 60][(farm->posx / 60) - 1] == 'E')
	{
		farm->fdir = 'L';
		return (farm);
	}
	farm->posx -= 60;
	return (farm);
}

t_farmer	*move_farmer_up(t_farmer *farm, char **map)
{
	if (map[(farm->posy / 60) - 1][farm->posx / 60] == '1'
		|| map[(farm->posy / 60) - 1][farm->posx / 60] == 'E')
	{
		farm->fdir = 'D';
		return (farm);
	}
	farm->posy -= 60;
	return (farm);
}

t_farmer	*move_farmer_down(t_farmer *farm, char **map)
{
	if (map[(farm->posy / 60) + 1][farm->posx / 60] == '1'
		|| map[(farm->posy / 60) + 1][farm->posx / 60] == 'E')
	{
		farm->fdir = 'U';
		return (farm);
	}
	farm->posy += 60;
	return (farm);
}

void	render_farmer(t_data *d)
{
	t_farmer	*tmp;
	char		c;

	check_gameover(d);
	tmp = d->farm->next;
	while (tmp != NULL)
	{
		c = tmp->fdir;
		if (c == 'D')
			tmp = move_farmer_down(tmp, d->map);
		if (c == 'U')
			tmp = move_farmer_up(tmp, d->map);
		if (c == 'L')
			tmp = move_farmer_left(tmp, d->map);
		if (c == 'R')
			tmp = move_farmer_right(tmp, d->map);
		tmp = tmp->next;
	}
	check_gameover(d);
}
