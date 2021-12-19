/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp0argvtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 03:03:17 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/19 20:57:05 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rempargv(char tab[6][6], char *argv)
{
	tab[0][1] = argv[0];
	tab[0][2] = argv[2];
	tab[0][3] = argv[4];
	tab[0][4] = argv[6];
	tab[5][1] = argv[8];
	tab[5][2] = argv[10];
	tab[5][3] = argv[12];
	tab[5][4] = argv[14];
	tab[1][0] = argv[16];
	tab[2][0] = argv[18];
	tab[3][0] = argv[20];
	tab[4][0] = argv[22];
	tab[1][5] = argv[24];
	tab[2][5] = argv[26];
	tab[3][5] = argv[28];
	tab[4][5] = argv[30];
}

void	ft_remp0argvtab(char tab[6][6], char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			tab[i][j] = '0';
			j++;
		}
		i++;
		j = 0;
	}
	ft_rempargv(tab, argv);
}
