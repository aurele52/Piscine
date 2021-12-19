/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:41:25 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:02:46 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_prototypes.h"

void	ft_printhundred(char *str)
{
	int	i;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0')
			i = i + 3;
		while (str[i] == ' ')
			i++;
		if (str[i++] == ':')
		{
			while (str[i] == ' ')
				i++;
			while (str[i] >= 32 && str[i] < 127)
				ft_write(str, &written, i++, -1);
			i = -1;
		}
		else
			i = ft_skip(str, i);
	}
}

void	ft_foisdix(char *str, char d, int j)
{
	int	i;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == d && str[i + 1] == '0')
			i = i + 2;
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

void	ft_dizaine(char *str, char *nbr, int j, int i)
{
	int	written;

	written = 0;
	while (str[i] && i >= 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == nbr[j] && str[i + 1] == nbr[j + 1])
			i = i + 2;
		while (str[i] == ' ')
			i++;
		if (str[i++] == ':')
		{
			while (str[i] == ' ')
				i++;
			while (str[i] >= 32 && str[i] < 127 )
				ft_write(str, &written, i++, j);
			i = -1;
		}
		else
			i = ft_skip(str, i);
	}
}
