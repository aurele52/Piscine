/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:43:11 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:03:07 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_prototypes.h"

void	ft_printsep1(char *str, int zero, char *nbr, int j)
{
	int	i;
	int	a;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		ft_print_sep_skip(str, &i, zero, &a);
		if (str[i] == ':' && a == zero && (nbr[j - 4] != '0'))
		{
			i++;
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

void	ft_printsep0(char *str, int zero, char *nbr, int j)
{
	int	i;
	int	a;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		a = 0;
		ft_print_sep_skip(str, &i, zero, &a);
		if (str[i] == ':' && a == zero && (nbr[j - 4] != '0'
				|| nbr[j - 5] != '0' || nbr[j - 6] != '0'))
		{
			i++;
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

void	ft_printsep2(char *str, int zero, char *nbr, int j)
{
	int	i;
	int	a;
	int	written;

	i = 0;
	written = 0;
	while (str[i] && i >= 0)
	{
		a = 0;
		ft_print_sep_skip(str, &i, zero, &a);
		if (str[i] == ':' && a == zero
			&& (nbr[j - 4] != '0' || nbr[j - 5] != '0'))
		{
			i++;
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

void	ft_sep_inc(int *a, int *i)
{
	*i = *i + 3;
	*a = *a + 3;
}

void	ft_separateur(char *str, char *nbr)
{
	int	i;
	int	a;

	a = 0;
	i = ft_intlen(nbr) % 3;
	if (i == 0)
		ft_sep_inc(&a, &i);
	if (i < ft_intlen(nbr))
	{
		if (i == 1)
			ft_printsep1(str, (ft_intlen(nbr) / 3) * 3 - a, nbr, i + 3);
		if (i == 3)
			ft_printsep0(str, (ft_intlen(nbr) / 3) * 3 - a, nbr, i + 3);
		if (i == 2)
			ft_printsep2(str, (ft_intlen(nbr) / 3) * 3 - a, nbr, i + 3);
		ft_triplet(str, nbr, i);
		ft_sep_inc(&a, &i);
	}
	while (i < ft_intlen(nbr))
	{
		ft_printsep0(str, (ft_intlen(nbr) / 3) * 3 - a, nbr, i + 3);
		ft_triplet(str, nbr, i);
		ft_sep_inc(&a, &i);
	}
}
