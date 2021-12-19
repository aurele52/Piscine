/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:28:39 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 00:43:15 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				b;

	b = 0;
	i = 0;
	while (dest[b])
		b++;
	while (src[i] && i < nb)
	{
		dest[b] = src[i];
		b++;
		i++;
	}
	dest[b] = 0;
	return (dest);
}
