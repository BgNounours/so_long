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

void	pre_end(t_data *d)
{
	int			i;
	t_farmer	*tmp;

	i = 0;
	tmp = d->farm->next;
	while (i != d->height + 1)
	{
		free(d->map[i]);
		i++;
	}
	while (tmp != NULL)
	{
		free(d->farm);
		d->farm = tmp;
		tmp = tmp->next;
	}
	free(d->farm);
	free(d->map);
	free(d);
}

int	end(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	mlx_destroy_image(d->mlx, d->img.floor);
	mlx_destroy_image(d->mlx, d->img.collec[0]);
	mlx_destroy_image(d->mlx, d->img.wall);
	mlx_destroy_image(d->mlx, d->img.cow[0]);
	mlx_destroy_image(d->mlx, d->img.farm[0]);
	mlx_destroy_image(d->mlx, d->img.exit[0]);
	mlx_loop_end(d->mlx);
	mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d->img.cow);
	free(d->img.exit);
	free(d->img.collec);
	free(d->farm);
	pre_end(d);
	exit(0);
}

void	win(t_data *d)
{
	write(1, "Good Job, you won in only ", 26);
	ft_putnbr(d->nb_move);
	write(1, " movements\n", 11);
	end(d);
}
