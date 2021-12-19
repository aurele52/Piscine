/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:13:27 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 14:24:20 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	resultat;

	sign = 1;
	i = 0;
	resultat = 0;
	while (((str[i] <= 13 && str[i] >= 9)
			|| str[i] == 32) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-')
		&& str[i])
	{
		if (str[i] == '-')
			sign = -(sign);
		i++;
	}
	while ((str[i] <= '9' && str[i] >= '0')
		&& str[i])
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (resultat * sign);
}
