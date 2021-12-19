/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:45:38 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/10 02:23:46 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	l;

	i = 0;
	l = 1;
	while (i < size)
	{
		while (l < size)
		{
			if(tab[i] > tab[l])
				ft_swap(&tab[i], &tab[l]);
			l++;
		}
		i++;
		l = i + 1;
	}
}
