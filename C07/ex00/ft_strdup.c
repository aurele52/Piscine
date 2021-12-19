/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:42:28 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/24 13:19:41 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (src[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = 0;
	while (b < i)
	{
		str[b] = src[b];
		b++;
	}
	return (str);
}
