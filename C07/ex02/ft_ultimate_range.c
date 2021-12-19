/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:04:11 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/24 13:21:42 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	temp;

	i = 0;
	temp = min;
	if (max <= min)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (0);
	while (i < max - min)
	{
		range[0][i] = temp;
		i++;
		temp++;
	}
	return (max - min);
}
