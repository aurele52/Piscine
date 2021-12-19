/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:39:56 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/28 18:14:51 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (a == charset[i] || a == 0)
			return (1);
		i++;
	}
	if (a == 0)
		return (1);
	return (0);
}

char	**ft_remp(char *str, char *charset, char **yolo, int wcount)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (wcount > 0)
	{
		while (str[i] && ft_is_charset(str[i], charset) == 1)
			i++;
		while (str[i] && ft_is_charset(str[i], charset) == 0)
		{
			yolo[b][a] = str[i];
			i++;
			a++;
		}
		wcount--;
		b++;
		a = 0;
	}
	return (yolo);
}

int	ft_wcount(char *str, char *charset)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i + 1], charset) == 1
			&& ft_is_charset(str[i], charset) == 0)
			wcount++;
		i++;
	}
	return (wcount);
}

char	**ft_split2(char *str, char *charset, int b, int i)
{
	char	**yolo;
	int		a;

	yolo = (char **)malloc(sizeof(char *) * (ft_wcount(str, charset) + 1));
	if (yolo == 0)
		return (0);
	yolo[ft_wcount(str, charset)] = 0;
	while (str[i])
	{
		a = 0;
		while (str[i] && ft_is_charset(str[i], charset) == 1)
			i++;
		while (str[i] && ft_is_charset(str[i], charset) == 0 && a++ >= 0)
			i++;
		if (a > 0)
		{
			yolo[b] = (char *)malloc(sizeof(char) * a + 1);
			if (yolo[b] == 0)
				return (0);
			yolo[b][a] = 0;
		}
		b++;
	}
	return (ft_remp(str, charset, yolo, ft_wcount(str, charset)));
}

char	**ft_split(char *str, char *charset)
{
	return (ft_split2(str, charset, 0, 0));
}
