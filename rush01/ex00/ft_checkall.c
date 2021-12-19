/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:45:21 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/19 20:56:43 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkdown(char tab[6][6])
{
	int	i;
	int	j;
	int	max;
	int	mem;

	j = 5;
	while (--j > 0)
	{
		max = '0';
		mem = '0';
		i = 5;
		while (--i > 0)
		{
			if (tab[i][j] > max)
			{
				max = tab[i][j];
				mem++;
			}
		}
		if (mem != tab[5][j])
			return (0);
	}
	return (1);
}

int	checkleft(char tab[6][6])
{
	int	i;
	int	j;
	int	max;
	int	mem;

	j = 0;
	while (++j < 5)
	{
		max = '0';
		mem = '0';
		i = 0;
		while (++i < 5)
		{
			if (tab[j][i] > max)
			{
				max = tab[j][i];
				mem++;
			}
		}
		if (mem != tab[j][0])
			return (0);
	}
	return (1);
}

int	checkright(char tab[6][6])
{
	int	i;
	int	j;
	int	max;
	int	mem;

	j = 5;
	while (--j > 0)
	{
		max = '0';
		mem = '0';
		i = 5;
		while (--i > 0)
		{
			if (tab[j][i] > max)
			{
				max = tab[j][i];
				mem++;
			}
		}
		if (mem != tab[j][5])
			return (0);
	}
	return (1);
}

int	checkup(char tab[6][6])
{
	int	i;
	int	j;
	int	max;
	int	mem;

	j = 0;
	while (++j < 5)
	{
		max = '0';
		mem = '0';
		i = 0;
		while (++i < 5)
		{
			if (tab[i][j] > max)
			{
				max = tab[i][j];
				mem++;
			}
		}
		if (mem != tab[0][j])
			return (0);
	}
	return (1);
}

int	ft_checkall(char tab[6][6])
{
	int	c;

	c = 0;
	c = c + checkright(tab);
	c = c + checkleft(tab);
	c = c + checkdown(tab);
	c = c + checkup(tab);
	if (c == 4)
		return (1);
	return (0);
}
