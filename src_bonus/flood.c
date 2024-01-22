/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:40 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/12 09:17:14 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	test_border(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (d->map[0][x] != '\0')
	{
		if (d->map[0][x] != '1' && d->map[0][x] != '\n')
			return (0);
		x++;
	}
	x = 0;
	while (y < d->height - 1)
	{
		if (d->map[y][0] != '1' || d->map[y][d->width - 2] != '1')
			return (0);
		y++;
	}
	while (d->map[y][x] != '\0')
	{
		if (d->map[y][x] != '1' && d->map[y][x] != '\n')
			return (0);
		x++;
	}
	return (1);
}

static void	check_path(t_data *d, char **tmp, int x, int y)
{
	if (tmp[y][x] == '1' || tmp[y][x] == '2')
		return ;
	if (tmp[y][x] == 'C' || tmp[y][x] == 'E' || tmp[y][x] == 'D'
		|| tmp[y][x] == 'U' || tmp[y][x] == 'R' || tmp[y][x] == 'L')
		d->flood_data--;
	tmp[y][x] = '2';
	check_path(d, tmp, x - 1, y);
	check_path(d, tmp, x + 1, y);
	check_path(d, tmp, x, y - 1);
	check_path(d, tmp, x, y + 1);
}

static char	**map_dup(t_data *d)
{
	char	**re;
	int		x;
	int		y;

	re = malloc(sizeof(char *) * d->height);
	y = 0;
	while (y < d->height)
	{
		re[y] = malloc(sizeof(char) * d->width + 1);
		x = 0;
		while (x < d->width)
		{
			re[y][x] = d->map[y][x];
			x++;
		}
		re[y][x] = '\0';
		y++;
	}
	return (re);
}

static void	free_tmp(char **tmp, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->height)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

t_data	*flood_fill(t_data *d)
{
	char	**tmp;

	if (test_border(d) == 0)
		d->good_map = 0;
	if (d->good_map == 0)
		return (d);
	tmp = map_dup(d);
	check_path(d, tmp, d->posx / 60, d->posy / 60);
	if (d->flood_data != 0)
		d->good_map = 0;
	free_tmp(tmp, d);
	return (d);
}
