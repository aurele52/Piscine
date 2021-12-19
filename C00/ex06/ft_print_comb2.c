/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:42:20 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/08 23:37:52 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int a, int b)
{
	char	u;
	char	d;

	d = a / 10 + '0';
	u = a % 10 + '0';
	write(1, &d, 1);
	write(1, &u, 1);
	write(1, " ", 1);
	d = b / 10 + '0';
	u = b % 10 + '0';
	write(1, &d, 1);
	write(1, &u, 1);
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 98)
	{
		while (b <= 99)
		{
			ft_putchar(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
	write(1, "98 99", 5);
}
