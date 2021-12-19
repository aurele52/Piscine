/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:28:39 by ayakdi            #+#    #+#             */
/*   Updated: 2021/09/12 20:31:21 by ayakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (++j <= y)
	{
		while (++i <= x)
		{
			if ((i == 1 && j == 1) || (i == x && j == y))
				ft_putchar('/');
			else if ((i == x && j == 1) || (i == 1 && j == y))
				ft_putchar('\\');
			else if ((i > 1 && i < x && j == 1) || (i > 1 && i < x && j == y)
				|| (i == 1 && j > 1 && j < y) || (i == x && j > 1 && j < y))
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		if (j <= y)
			ft_putchar('\n');
		i = 0;
	}
}
