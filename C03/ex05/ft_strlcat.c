/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 04:28:22 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 14:20:30 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;
	unsigned int	destlen;
	unsigned int	i;
	unsigned int	mem;

	i = 0;
	destlen = 0;
	srclen = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	mem = destlen;
	if (size < 1)
		return (srclen + size);
	while (src[i] && mem < size - 1)
	{
		dest[mem] = src[i];
		i++;
		mem++;
	}
	dest[mem] = 0;
	if (size < destlen)
		return (srclen + size);
	else
		return (srclen + destlen);
}
