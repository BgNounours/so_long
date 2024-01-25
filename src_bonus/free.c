/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
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
	tmp = NULL;
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

void	free_img(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img.floor);
	mlx_destroy_image(d->mlx, d->img.collec[0]);
	mlx_destroy_image(d->mlx, d->img.collec[1]);
	mlx_destroy_image(d->mlx, d->img.wall);
	mlx_destroy_image(d->mlx, d->img.cow[0]);
	mlx_destroy_image(d->mlx, d->img.cow[1]);
	mlx_destroy_image(d->mlx, d->img.cow[2]);
	mlx_destroy_image(d->mlx, d->img.cow[3]);
	mlx_destroy_image(d->mlx, d->img.farm[0]);
	mlx_destroy_image(d->mlx, d->img.farm[1]);
	mlx_destroy_image(d->mlx, d->img.exit[0]);
	mlx_destroy_image(d->mlx, d->img.exit[1]);
	mlx_destroy_image(d->mlx, d->img.score[0]);
	mlx_destroy_image(d->mlx, d->img.score[1]);
	mlx_destroy_image(d->mlx, d->img.score[2]);
	destroy_nb(d);
}

int	end(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	free_img(d);
	mlx_loop_end(d->mlx);
	mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d->img.cow);
	free(d->img.exit);
	free(d->img.collec);
	free(d->img.farm);
	free(d->img.score);
	pre_end(d);
	return (0);
}

int	end_exit(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	free_img(d);
	mlx_loop_end(d->mlx);
	mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d->img.cow);
	free(d->img.exit);
	free(d->img.collec);
	free(d->img.farm);
	free(d->img.score);
	pre_end(d);
	exit (0);
}

int	end_game(int keycode, t_data *d)
{
	if (keycode != 0)
	{
		mlx_clear_window(d->mlx, d->win);
		mlx_destroy_image(d->mlx, d->img.menu);
		mlx_loop_end(d->mlx);
		mlx_destroy_window(d->mlx, d->win);
		if (d->mlx)
			mlx_destroy_display(d->mlx);
		free(d->mlx);
		free(d->img.cow);
		free(d->img.exit);
		free(d->img.collec);
		free(d->img.farm);
		free(d->img.score);
		pre_end(d);
	}
	exit(0);
	return (0);
}
