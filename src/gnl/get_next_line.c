/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:56:11 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/19 13:28:02 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"
#include "../../include/so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	rd = 1;
	while (ft_strchr_get(str, '\n') == 0 && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin_get(str, buff);
	}
	free(buff);
	return (str);
}

static int	norm_get_malloc_size(char *s, int i)
{
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (NULL);
	i = norm_get_malloc_size(s, i);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_next_str(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	str = malloc(sizeof(char) * (ft_strlen_get(s) - (i) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*re;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	re = ft_get_line(str);
	str = ft_next_str(str);
	return (re);
}
