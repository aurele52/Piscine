/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:41:01 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:02:36 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_prototypes.h"

int	ft_intlen(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
		i++;
	return (i);
}

int	ft_skip(char *str, int i)
{
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	return (i);
}

void	ft_write(char *str, int *written, int i, int j)
{
	if (!(*written) && j != 0)
		write(1, " ", 1);
	(*written) = 1;
	write(1, &str[i], 1);
}

void	ft_num(char *str, char a, int j)
{
	int	i;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == a)
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i++] == ':')
		{
			while (str[i] == ' ')
				i++;
			while (str[i] >= 32 && str[i] < 127)
				ft_write(str, &written, i++, j);
			i = -1;
		}
		else
			i = ft_skip(str, i);
	}
}
