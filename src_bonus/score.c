/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:16:31 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/11 13:34:37 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../include/so_long_bonus.h"

t_data	*set_nbr_img(t_data *d)
{
	int	s;

	s = 30;
	d->img.nb = malloc(sizeof(void *) * 10);
	d->img.nb[0] = mlx_xpm_file_to_image(d->mlx, "img/s/0.xpm", &s, &s);
	d->img.nb[1] = mlx_xpm_file_to_image(d->mlx, "img/s/1.xpm", &s, &s);
	d->img.nb[2] = mlx_xpm_file_to_image(d->mlx, "img/s/2.xpm", &s, &s);
	d->img.nb[3] = mlx_xpm_file_to_image(d->mlx, "img/s/3.xpm", &s, &s);
	d->img.nb[4] = mlx_xpm_file_to_image(d->mlx, "img/s/4.xpm", &s, &s);
	d->img.nb[5] = mlx_xpm_file_to_image(d->mlx, "img/s/5.xpm", &s, &s);
	d->img.nb[6] = mlx_xpm_file_to_image(d->mlx, "img/s/6.xpm", &s, &s);
	d->img.nb[7] = mlx_xpm_file_to_image(d->mlx, "img/s/7.xpm", &s, &s);
	d->img.nb[8] = mlx_xpm_file_to_image(d->mlx, "img/s/8.xpm", &s, &s);
	d->img.nb[9] = mlx_xpm_file_to_image(d->mlx, "img/s/9.xpm", &s, &s);
	return (d);
}

void	put_nbr_windows(t_data *d, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[0], x, y);
	if (c == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[1], x, y);
	if (c == '2')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[2], x, y);
	if (c == '3')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[3], x, y);
	if (c == '4')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[4], x, y);
	if (c == '5')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[5], x, y);
	if (c == '6')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[6], x, y);
	if (c == '7')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[7], x, y);
	if (c == '8')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[8], x, y);
	if (c == '9')
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[9], x, y);
}

void	render_score(t_data *d, char *score)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(d->mlx, d->win, d->img.score[0], 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->img.score[1], 60, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->img.score[2], 120, 0);
	if (ft_strlen(score) == 3)
	{
		put_nbr_windows(d, score[i], 40, 15);
		i++;
	}
	else
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[0], 45, 15);
	if (ft_strlen(score) >= 2)
	{
		put_nbr_windows(d, score[i], 75, 10);
		i++;
	}
	else
		mlx_put_image_to_window(d->mlx, d->win, d->img.nb[0], 75, 10);
	put_nbr_windows(d, score[i], 110, 15);
	free(score);
}

void	destroy_nb(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img.nb[0]);
	mlx_destroy_image(d->mlx, d->img.nb[1]);
	mlx_destroy_image(d->mlx, d->img.nb[2]);
	mlx_destroy_image(d->mlx, d->img.nb[3]);
	mlx_destroy_image(d->mlx, d->img.nb[4]);
	mlx_destroy_image(d->mlx, d->img.nb[5]);
	mlx_destroy_image(d->mlx, d->img.nb[6]);
	mlx_destroy_image(d->mlx, d->img.nb[7]);
	mlx_destroy_image(d->mlx, d->img.nb[8]);
	mlx_destroy_image(d->mlx, d->img.nb[9]);
	free(d->img.nb);
}
