/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:18:55 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/23 19:25:09 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_valabs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_print(int *echec)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = echec[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_lignes(char res, int pos, int echec[10])
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (echec[i] == res)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos)
	{
		if (ft_valabs(res - echec[i]) == ft_valabs(pos - i))
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(int echec[10], int pos, int *yes)
{
	char	res;

	res = 0;
	while (res <= 9)
	{
		if (check_lignes(res, pos, echec))
		{
			echec[pos] = res;
			if (pos < 9)
				ft_backtrack(echec, pos + 1, yes);
			else
			{
				ft_print(echec);
				*yes = *yes + 1;
			}
		}
		res++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	echec[10];
	int	nb;

	nb = 0;
	ft_backtrack(echec, 0, &nb);
	return (nb);
}
