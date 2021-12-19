/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:00:13 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 17:30:32 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	temp = nb;
	while (power - 1 != 0)
	{
		nb = nb * temp;
		power--;
	}
	return (nb);
}
