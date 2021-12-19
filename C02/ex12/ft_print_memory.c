/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:03:40 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/17 14:52:11 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printalpha(void *addr, unsigned int size)
{
	char				*b;
	unsigned int		i;
	char				c;

	i = 0;
	b = addr;
	while (i < 16 && i < size)
	{
		c = b[i];
		if (b[i] < 32 || b[i] == 127)
			c = '.';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_printcharhexa(void *addr, unsigned int size)
{
	char				c;
	unsigned int		i;
	char				*b;
	char				*hexa;

	i = 0;
	b = addr;
	hexa = "0123456789abcdef";
	while (i < 16 && i < size)
	{
		c = hexa[b[i] / 16];
		write(1, &c, 1);
		c = hexa[b[i] % 16];
		write(1, &c, 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ftaddrhexa(long unsigned int addr, int o, int zerocount, long int rev)
{
	char	c;
	char	*hexa;

	hexa = "0123456789abcdef";
	while (addr > 0)
	{
		if (addr % 16 == 0 && rev == 0)
			zerocount = zerocount + 1;
		rev = addr % 16 + rev * 16;
		addr = addr / 16;
		o++;
	}
	while (16 >= ++o)
		write(1, "0", 1);
	while (rev > 0)
	{
		c = hexa[rev % 16];
		rev = rev / 16;
		write(1, &c, 1);
	}
	while (zerocount > 0)
	{
		write(1, "0", 1);
		zerocount--;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long int	i;

	i = (long int)size;
	while (i > 0)
	{
		ftaddrhexa((long unsigned int)addr, 0, 0, 0);
		write(1, ": ", 2);
		ft_printcharhexa(addr, size);
		ft_printalpha(addr, size);
		addr = addr + 16;
		i = i - 16;
		if (size > 0)
			size = size - 16;
	}
	return (addr);
}
