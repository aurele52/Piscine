/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:07:25 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/28 18:26:45 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libc.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (src[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = 0;
	while (b < i)
	{
		str[b] = src[b];
		b++;
	}
	return (str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strustr;
	int			i;

	i = 0;
	strustr = malloc(sizeof(t_stock_str) * (ac + 1));
	while (i < ac)
	{
		strustr[i].size = ft_strlen(av[i]);
		strustr[i].copy = ft_strdup(av[i]);
		strustr[i].str = av[i];
		i++;
	}
	strustr[i].str = 0;
	return (strustr);
}
