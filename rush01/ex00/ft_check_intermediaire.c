/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:09:48 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/19 20:56:21 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_inter_lignes(int pos, int y, int x, char tab[6][6])
{
	int	i;

	i = 1;
	while (i < x)
	{
		if (tab[y][i] == pos + '0' && i != x)
			return (0);
		i++;
	}
	return (1);
}

int	check_inter_colonne(int pos, int y, int x, char tab[6][6])
{
	int	j;

	j = 1;
	while (j < y)
	{
		if (tab[j][x] == pos + '0' && j != y)
			return (0);
		j++;
	}
	return (1);
}
