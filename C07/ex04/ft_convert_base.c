/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 06:15:34 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/24 13:07:29 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_truth(int greed, int sign, char *base_tom)
{
	int		a;
	int		temp;
	char	*freedom;

	temp = greed;
	a = 0;
	while (temp / ft_strlen(base_tom) > 0 && ++a > -1)
		temp = temp / ft_strlen(base_tom);
	freedom = malloc(sizeof(char) * a + 2 + sign);
	if (*freedom == 0)
		return (0);
	if (sign == 1)
	{
		freedom[0] = '-';
		a++;
	}
	freedom[a + 1] = 0;
	while ((a >= 0 && sign == 0) || (a > 0 && sign == 1))
	{
		freedom[a--] = base_tom[greed % ft_strlen(base_tom)];
		greed = greed / ft_strlen(base_tom);
	}
	return (freedom);
}

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
				|| base[i] == '-' || base[i] == ' '
				|| (base[i] <= 13 && base[i] >= 9))
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

char	*ft_convert_nbr(char *nbrm, char *base_fromm, char *base_tom, int sign)
{
	int	j;
	int	i;
	int	existence;

	existence = 0;
	i = 0;
	j = 0;
	while (nbrm[i])
	{
		while (base_fromm[j] != nbrm[i] && base_fromm[j])
			j++;
		if (base_fromm[j] == nbrm[i])
		{
			existence = existence * ft_strlen(base_fromm) + j;
			i++;
			j = 0;
		}
		else
			return (ft_truth(existence, sign, base_tom));
	}
	return (ft_truth(existence, sign, base_tom));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	char	*nbrm;
	char	*base_fromm;
	char	*base_tom;

	nbrm = nbr;
	base_fromm = base_from;
	base_tom = base_to;
	sign = 0;
	if (ft_checkbase(base_fromm) == -1 && ft_checkbase(base_tom) == -1)
		return (0);
	while (((*nbrm <= 13 && *nbrm >= 9) || *nbrm == 32) && *nbrm)
		nbrm++;
	while ((*nbrm == '+' || *nbrm == '-') && *nbrm)
	{
		if (*nbrm == '-')
			sign = sign + 1;
		nbrm++;
	}
	return (ft_convert_nbr(nbrm, base_fromm, base_tom, sign % 2));
}
