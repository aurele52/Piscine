/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:50:21 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/29 21:19:34 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 100

void ft_sort_map( char **tab_map, t_info info, t_coordo coordo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < info.line)
	{
		while (i < info.column)
		{
			if (tab_map[j][i] == 127)
				write(1, &info.obstacle, 1);
			else if ((j >= coordo.y && j < coordo.y + coordo.size) && (i >= coordo.x && i < coordo.x + coordo.size))
				write(1, &info.full, 1);
			else
				write(1, &info.empty, 1);
			i++;
		}
		write(1,"\n",1);
		j++;
		i = 0;
	}
}

void	ft_create_maptab(char *str_map_no_first_line, t_info info)
{
	int		i;
	int		j;
	int		f;
	int		error;
	char	**tab_map;
	t_doubled	*list;

	list = malloc(sizeof(*list) * info.ligne * info.column + 1);
	tab_map = malloc(sizeof( char*) * (info.line + 1));
	i = 0;
	error = 0;
	j = 0;
	f = 0;
	while(str_map_no_first_line[f] && error == 0)
	{
		tab_map[j] = malloc(sizeof( char) * (info.column + 1));
		tab_map[j][info.column] = 0;
		while (i < info.column  && error == 0)
		{
			if (str_map_no_first_line[f] != info.empty && str_map_no_first_line[f] != info.obstacle)
				error = -2;
			if (str_map_no_first_line[f] == info.empty)
				tab_map[j][i] = 0;
			else
				tab_map[j][i] = 127;
			list[f].line = j;
			list[f].column = i;
			i++;
			f++;
		}
		if (str_map_no_first_line[f] != '\n')
			error = -1;
		i = 0;
		f++;
		j++;
	}
	if (error == -1)
		write(1,"map error\n",10);
	else
		t_doubled   *ft_double_grid(tab_map, list, 1, info);
}

t_doubled	ft_create_initial_list(char **tab)
{
	int	index1;
	int	index2;
	while (*
}

char *ft_str_map_next_line(char *str_map)
{
	int	i;

	i = 0;
	while (*str_map != '\n')
		str_map++;
	return (str_map + 1);
}

int	ft_line_number(char *str_map)
{
	int	i;
	int	b;
	int	ret;

	ret = 0;
	i = 0;
	while (str_map[i] != '\n' && str_map[i])
		i++;
	if (str_map[i] == 0)
		return (-1);
	i = i - 4;
	b = 0;
	while (str_map[b] <= '9' && str_map[b] >= '0' && b <= i)
	{
		ret = (str_map[b] - '0') + ret * 10;
		b++;
	}
	if (i + 1 != b)
		return (-1);
	return (ret);
}

int	ft_column_number(char *str_map)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str_map[i] != '\n' && str_map[i])
		i++;
	if (str_map[i] == 0)
		return (-1);
	i++;
	while (str_map[i + b] != '\n' && str_map[i + b])
		b++;
	if (b == 0)
		return (-1);
	return (b);
}

int	ft_obstacle_find(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i] != '\n' && str_map[i])
		i++;
	if (str_map[i] == 0)
		return (-1);
	i = i - 2;
	if (str_map[i] < 32 || str_map[i] == 127)
		return (-1);
	return (str_map[i]);
}

int	ft_empty_find(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i] != '\n' && str_map[i])
		i++;
	if (str_map[i] == 0)
		return (-1);
	i = i - 3;
	if (str_map[i] < 32 || str_map[i] == 127)
		return (-1);
	return (str_map[i]);
}

int	ft_full_find(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i] != '\n' && str_map[i])
		i++;
	if (str_map[i] == 0)
		return (-1);
	i = i - 1;
	if (str_map[i] < 32 || str_map[i] == 127)
		return (-1);
	return (str_map[i]);
}

void	ft_total(char *str_map)
{
	t_info			info;
	t_coordo		coordo;
	 char	**tab_map;

	coordo.x = 2;
	coordo.y = 2;
	coordo.size = 4;

	info.line = ft_line_number(str_map);
	info.column	= ft_column_number(str_map);
	info.obstacle = ft_obstacle_find(str_map);
	info.empty = ft_empty_find(str_map);
	info.full = ft_full_find(str_map);
	if (info.line == -1 || info.column == -1 || info.obstacle == -1 || info.empty == -1 || info.full == -1 || (info.obstacle == info.empty || info.obstacle == info.full || info.full == info.empty))
	{
		write(1,"map error\n",10);
		return;
	}
	str_map = ft_str_map_next_line(str_map);
	if (str_map[info.line * info.column + info.line] != 0 && str_map[info.line * info.column + info.line - 1] != '\n') 
	{
		write(1,"map error\n",10);
		return;
	}
	tab_map = ft_create_maptab(str_map, info);
	if (tab_map[0][0] != 126)
		ft_sort_map(tab_map, info, coordo);
	else
		write(1,"map error\n",10);
}

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

void	ft_parse_file(char *map_path)
{
	char	*buffer;
	int		fd;
	int		ret;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return ;
	ret = ft_file_size(map_path);
	if (ret == -1)
		return ;
	buffer = malloc(ret * sizeof(char) + 1);
	if (!buffer)
		return ;
	ret = read(fd, buffer, ret);
	buffer[ret] = 0;
	if (close(fd) == -1)
		return ;
	ft_total(buffer);
	free(buffer);
}

void	ft_stdin(void)
{
	char	buffer;
	int		fd;

	fd = open("a.txt", O_CREAT | O_WRONLY | O_TRUNC);
	while(read(STDIN_FILENO, &buffer, 1))
		write(fd, &buffer, 1);
	ft_parse_file("a.txt");
}




