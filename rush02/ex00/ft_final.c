/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:44:09 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:17:07 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_prototypes.h"

void	ft_final(char *str, char *nbr)
{
	int	tri;
	int	i;

	i = 0;
	tri = ft_intlen(nbr) % 3;
	if (tri == 0)
		 ft_triplet(str, nbr, i);
	else if (tri == 1)
		ft_num(str, nbr[i], i);
	else if (nbr[i] == '1')
		ft_dizaine(str, nbr, i, 0);
	else
	{
		ft_foisdix(str, nbr[i], i);
		if (nbr[i + 1] != '0')
			ft_num(str, nbr[i + 1], i + 1);
	}
	if (ft_intlen(nbr) > 3)
		ft_separateur(str, nbr);
}

int	ft_checktab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] != ':')
			return (-1);
		i++;
		while (str[i] == ' ')
			i++;
		while (str[i] >= 32 && str[i] < 127)
			i++;
		if (str[i] != '\n' && str[i] != 0)
			return (-1);
		i++;
	}
	return (i);
}

void	ft_suite(char *str, char *nb)
{
	ft_checktab(str);
	ft_final(str, nb);
}

int	ft_return(char *buffer)
{
	write(1, "Error\n", 6);
	free(buffer);
	return (-1);
}

int	ft_parse_file(char *dict_path, char *nb)
{
	char	*buffer;
	int		fd;
	int		ret;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	ret = ft_file_size(dict_path);
	if (ret == -1)
		return (-1);
	buffer = malloc(ret);
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, ret);
	buffer[ret] = 0;
	if (close(fd) == -1)
		return (ft_return(buffer));
	ft_suite(buffer, nb);
	free(buffer);
	return (ret);
}
