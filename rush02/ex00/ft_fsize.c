/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:14:38 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:21:42 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libc.h>
#define BUFFER_SIZE 512

int	ft_file_size(char *dict_path)
{
	int		file_total_size;
	int		size_read;
	int		fd;
	char	buffer[BUFFER_SIZE];

	fd = open(dict_path, O_RDONLY);
	file_total_size = 0;
	size_read = 0;
	while (1)
	{
		size_read = read(fd, &buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			close(fd);
			return (-1);
		}
		file_total_size += size_read;
		if (size_read < BUFFER_SIZE)
		{
			close(fd);
			return (file_total_size);
		}
	}
	close(fd);
	return (-1);
}
