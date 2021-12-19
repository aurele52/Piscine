/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:48:42 by jyildiri          #+#    #+#             */
/*   Updated: 2021/09/19 20:57:50 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_arg(int argc, char **argv);
int	ft_checkall(char tab[6][6]);
int	ft_printtab4(char tab[6][6]);
int	ft_remp0argvtab(char tab[6][6], char *argv);
int	check_inter_lignes(int pos, int x, int y, char tab[6][6]);
int	check_inter_colonne(int pos, int x, int y, char tab[6][6]);

void	ft_backtrack(char tab[6][6], int i, int j, int *yes)
{
	int	a;

	a = 1;
	while (a <= 4)
	{
		if (check_inter_lignes(a, i, j, tab) == 1
			&& check_inter_colonne(a, i, j, tab) == 1)
		{
			tab[i][j] = a + '0';
			if (j < 4)
				ft_backtrack(tab, i, j + 1, yes);
			else if (i < 4)
				ft_backtrack(tab, i + 1, 1, yes);
			else if (ft_checkall(tab) && *yes == 0)
			{
				*yes = 1;
				ft_printtab4(tab);
			}
		}
		a++;
	}
}

int	main(int argc, char **argv)
{
	char	tab[6][6];
	int		a;
	int		*p;

	a = 0;
	p = &a;
	if (check_arg(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_remp0argvtab(tab, argv[1]);
	ft_backtrack(tab, 1, 1, p);
	if (a == 0)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
