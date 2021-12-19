/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:25:07 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 14:28:38 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_bordel(char *str, char *base, int j, int baselen)
{
	int	puis;
	int	res;
	int	i;

	j = j - 1;
	puis = 1;
	i = 0;
	res = 0;
	while (j >= 0)
	{
		while (base[i] != str[j])
			i++;
		res = res + i * puis;
		j--;
		i = 0;
		puis = puis * baselen;
	}
	return (res);
}

int	ft_base(char *str, char *base)
{
	int	res;
	int	i;
	int	j;
	int	baselen;

	j = 0;
	baselen = 0;
	i = 0;
	res = 0;
	while (base[baselen])
		baselen++;
	while (str[j])
	{
		while (str[j] != base[i] && base[i])
			i++;
		if (i == baselen)
			return (ft_bordel(str, base, j, baselen));
		j++;
		i = 0;
	}
	return (ft_bordel(str, base, j, baselen));
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

int	ft_atoi_base(char *str, char *base)
{
	int	moin;

	moin = 1;
	if (ft_checkbase(base) == -1)
		return (0);
	while (*str && ((*str <= 13 && *str >= 9)
			|| *str == ' '))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			moin = -(moin);
		str++;
	}
	return (ft_base(str, base) * moin);
}
