/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:42:40 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:03:18 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_prototypes.h"

int	ft_triplet(char *str, char *nbr, int i)
{
	if (nbr[i] != '0')
	{
		ft_num(str, nbr[i], i);
		ft_printhundred(str);
	}
	i++;
	if (nbr[i] == '0')
	{
		if (nbr[i + 1] != '0')
			ft_num(str, nbr[i + 1], i + 1);
		i = i + 2;
	}
	else if (nbr[i] == '1')
	{
		ft_dizaine(str, nbr, i, 0);
		i = i + 2;
	}
	else
	{
		ft_foisdix(str, nbr[i], i);
		if (nbr[i + 1] != '0')
			ft_num(str, nbr[i + 1], i + 1);
		i = i + 2;
	}
	return (i);
}

void	ft_print_sep_skip(char *str, int *i, int zero, int *a)
{
	*a = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '1' && str[*i + zero] == '0')
		(*i)++;
	while (str[*i] == '0')
	{
		(*i)++;
		(*a)++;
	}
	while (str[*i] == ' ')
		(*i)++;
}
