/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:27:34 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 14:26:16 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_checkbase(char *base)
{
	int	baselen;
	int	i;

	i = 1;
	baselen = 0;
	while (base[baselen])
	{
		while (base[i])
		{
			if (base[i] == base[baselen] || base[i] == '+'
				|| base[i] == '-')
				return (-1);
			i++;
		}
		baselen++;
		i = baselen + 1;
	}
	if (baselen <= 1)
		return (-1);
	return (0);
}

void	ft_baseswap(unsigned int b, char *base)
{
	char			i;
	unsigned int	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	if (b >= baselen)
		ft_baseswap(b / baselen, base);
	i = base[b % baselen];
	write(1, &i, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	b;

	b = 0;
	if (ft_checkbase(base) == -1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		b = -(nbr);
	}
	else
		b = nbr;
	ft_baseswap(b, base);
}
