/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:40:30 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/09 11:37:12 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_pow(int n, int pow)
{
	if (pow == 0 || n == 1)
		return (1);
	if (n == 0)
		return (0);
	return (n * ft_pow(n, pow - 1));
}

static int	ft_intlen(int n)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	if (n < 0)
	{
		n = -n;
		minus++;
	}
	while (n / ft_pow(10, i) > 9)
		i++;
	return (i + 1 + minus);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*out;

	size = ft_intlen(n) - 1;
	out = malloc(size + 2);
	if (out == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		out[i] = '-';
		n = -n;
		i++;
	}
	while (size - i >= 0)
	{
		out[i] = (n / ft_pow(10, size - i)) % 10 + '0';
		i++;
	}
	out[i] = '\0';
	return (out);
}
