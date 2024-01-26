/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:56:11 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/12 09:16:56 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	invalid_char(char c, char *valid_c)
{
	int	i;

	i = 0;
	while (valid_c[i] != '\0')
	{
		if (valid_c[i] == c || c == '\0')
			return (0);
		i++;
	}
	return (1);
}

static t_data	*norm_check(t_data *d, int x, int y)
{
	if (d->map[y][x] == 'P')
	{
		d->posx = x * 60;
		d->posy = y * 60;
		d->have_player++;
	}
	if (d->map[y][x] == 'E')
		d->have_exit++;
	if (d->map[y][x] == 'C')
		d->nbr_collec++;
	if (invalid_char(d->map[y][x], "01PCcEDULR\n") == 1)
		d->good_map = 0;
	return (d);
}

static t_data	*check_char(t_data *d)
{
	int	y;
	int	x;

	d->have_exit = 0;
	y = 0;
	x = 0;
	d->have_player = 0;
	d->nbr_collec = 0;
	while (y < d->height)
	{
		while (x < d->width)
		{
			d = norm_check(d, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	if (d->have_player != 1 || d->have_exit != 1 || d->nbr_collec == 0)
		d->good_map = 0;
	d->flood_data = d->nbr_collec + 1;
	return (d);
}

static int	wrong_line(t_data *d, int i)
{
	if (ft_strlen(d->map[i]) == d->width)
		return (0);
	if (ft_strlen(d->map[i]) == d->width - 1)
		return (0);
	return (-1);
}

t_data	*check_map(t_data *d)
{
	int	i;

	i = 1;
	d->good_map = 1;
	d->farm = malloc(sizeof(t_farmer) * 1);
	while (i < d->height)
	{
		if (wrong_line(d, i) < 0)
			d->good_map = 0;
		i++;
	}
	d = check_char(d);
	d->farm = get_farmer(d);
	if (d->farm->next != NULL)
		d->flood_data += nbr_of_farmer(d->farm);
	d = flood_fill(d);
	d->map[d->posy / 60][d->posx / 60] = '0';
	return (d);
}
