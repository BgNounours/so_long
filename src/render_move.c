/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:47:02 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/21 13:05:11 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*move_up(t_data *d)
{
	if (d->map[(d->posy - 1) / 60][d->posx / 60] == '1')
		return (d);
	if (d->map[(d->posy - 1) / 60][d->posx / 60] == 'E' && d->nbr_collec != 0)
		return (d);
	if (d->map[(d->posy - 1) / 60][d->posx / 60] == 'E' && d->nbr_collec == 0)
		win(d);
	d->posy -= 60;
	d->nb_move++;
	put_move(d);
	if (d->map[d->posy / 60][d->posx / 60] == 'C')
	{
		d->nbr_collec--;
		d->map[d->posy / 60][d->posx / 60] = '0';
	}
	return (d);
}

t_data	*move_down(t_data *d)
{
	d->posy += 60;
	if (d->map[d->posy / 60][d->posx / 60] == '1')
	{
		d->posy -= 60;
		return (d);
	}
	if (d->map[d->posy / 60][d->posx / 60] == 'E' && d->nbr_collec != 0)
	{
		d->posy -= 60;
		return (d);
	}
	if (d->map[d->posy / 60][d->posx / 60] == 'E' && d->nbr_collec == 0)
	{
		d->nb_move++;
		put_move(d);
		win(d);
	}
	d->nb_move++;
	put_move(d);
	if (d->map[d->posy / 60][d->posx / 60] == 'C')
	{
		d->nbr_collec--;
		d->map[d->posy / 60][d->posx / 60] = '0';
	}
	return (d);
}

t_data	*move_left(t_data *d)
{
	if (d->map[d->posy / 60][(d->posx - 1) / 60] == '1')
		return (d);
	if (d->map[d->posy / 60][(d->posx - 1) / 60] == 'E' && d->nbr_collec != 0)
		return (d);
	if (d->map[d->posy / 60][(d->posx - 1) / 60] == 'E' && d->nbr_collec == 0)
		win(d);
	d->posx -= 60;
	d->nb_move++;
	put_move(d);
	if (d->map[d->posy / 60][d->posx / 60] == 'C')
	{
		d->nbr_collec--;
		d->map[d->posy / 60][d->posx / 60] = '0';
	}
	return (d);
}

t_data	*move_right(t_data *d)
{
	d->posx += 60;
	if (d->map[d->posy / 60][d->posx / 60] == '1')
	{
		d->posx -= 60;
		return (d);
	}
	if (d->map[d->posy / 60][d->posx / 60] == 'E' && d->nbr_collec != 0)
	{
		d->posx -= 60;
		return (d);
	}
	if (d->map[d->posy / 60][d->posx / 60] == 'E' && d->nbr_collec == 0)
	{
		d->nb_move++;
		put_move(d);
		win(d);
	}
	d->nb_move++;
	put_move(d);
	if (d->map[d->posy / 60][d->posx / 60] == 'C')
	{
		d->nbr_collec--;
		d->map[d->posy / 60][d->posx / 60] = '0';
	}
	return (d);
}
