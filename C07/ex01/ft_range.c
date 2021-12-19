/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 03:40:14 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/24 13:20:50 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	i;

	i = 0;
	if (max - min <= 0)
		return (0);
	a = (int *)malloc(sizeof(int) * (max - min));
	if (a == 0)
		return (0);
	while (i < max - min)
	{
		a[i] = i + min;
		i++;
	}
	return (a);
}
