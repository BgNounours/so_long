/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:46:58 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/19 13:28:28 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_strchr_get(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_get(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen_get(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_get(char *s, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	if (s == NULL || buff == NULL)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_get(s) + ft_strlen_get(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_get(s) + ft_strlen_get(buff)] = '\0';
	free(s);
	return (str);
}
