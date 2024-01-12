/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:13:37 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/22 13:55:05 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**read_map(int fd, int height)
{
	char	**re;
	int		i;

	re = malloc(sizeof(char *) * (height + 2));
	i = 0;
	while (i <= height)
	{
		re[i] = get_next_line(fd);
		i++;
	}
	re[i] = NULL;
	return (re);
}

t_data	*get_map(t_data *d, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(d);
		return (NULL);
	}
	line = get_next_line(fd);
	d->height = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		d->height++;
	}
	free(line);
	close(fd);
	fd = open(file, O_RDONLY);
	d->map = read_map(fd, d->height);
	close(fd);
	d->width = ft_strlen(d->map[0]);
	return (d);
}
