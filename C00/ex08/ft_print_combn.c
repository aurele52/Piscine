/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:44:48 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/11 18:27:56 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printtab(char *tab, int n)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
	if (tab[0] < 10 - n + '0')
		write(1, ", ", 2);
}

void	ft_combn(char *tab, int n)
{
	int	a;

	a = n - 1;
	while (tab[0] != 10 - n + '0')
	{
		ft_printtab(tab, n);
		while (tab[a] == 10 - n + a + '0')
			a--;
		tab[a]++;
		while (a != n - 1)
		{
			a++;
			tab[a] = tab[a - 1] + 1;
		}
	}
	ft_printtab(tab, n);
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;

	if (n < 0 || n > 10)
		return ;
	i = 0;
	tab[n] = 0;
	while (i != n)
	{
		tab[i] = i + '0';
		i++;
	}
	ft_combn(tab, n);
}
