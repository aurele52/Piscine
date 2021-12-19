/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 03:18:22 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/24 00:42:22 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_join(char **strs, char *sep, char *chaine, int size)
{
	int	i;
	int	j;
	int	a;

	a = 0;
	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
			chaine[a++] = strs[i][j++];
		j = 0;
		i++;
		while (sep[j] && i != size)
			chaine[a++] = sep[j++];
		j = 0;
	}
	return (chaine);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		a;
	char	*chaine;

	j = -1;
	a = 0;
	i = -1;
	while (strs[++i])
	{
		while (strs[i][++j])
			a++;
		j = 0;
	}
	while (sep[j])
		j++;
	chaine = malloc(sizeof(char) * (a + 1 + j * (size - 1)));
	if (chaine == 0)
		return (0);
	chaine[a + (size - 1) * j] = 0;
	return (ft_join(strs, sep, chaine, size));
}
