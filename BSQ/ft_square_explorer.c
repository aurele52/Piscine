/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_explorer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athierry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:36:28 by athierry          #+#    #+#             */
/*   Updated: 2021/09/29 21:46:41 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
int	ft_power_two(char exponent)
{
	int	result;

	result = 1;
	while (exponent--)
		result *= 2;
	return (result);
}

int	ft_length_doub(t_doubled *list)
{
	int	index;

	index = 0;
	while (*list++)
		index++;
	return (index);
}
	
int	ft_double_case(t_doubled *position, char **tab)
{
	char	*current_value;

	current_value = (*(*(tab + *position.line) + *position.column))
	if (*(*(tab + *position.line + size) + *position.column) == *current_value)
	{
		if (*(*(tab + *position.line) + *position.column + size) == *current_value)
		{
			if (*(*(tab + *position.line + size) + *position.column + size) == *current_value)
			{
				(*current_value)++;
				return (1);
			}
		}
	}
	return (0);
}

t_doubled	*ft_double_grid(char **tab, t_doubled *previous_list, int size, t_info map)
{
	int			line;
	int			column;
	t_doubled	*new_list;
// malloc
	new_list = malloc(sizeof(*new_list) * ft_length(previous_list));
	while (*previous_list)
	{
		if ((*previous_list).line % size == 0 && (*previous_list).column % size == 0 && (*previous_list).column < map.column - (map.column % size) && (*previous_list).line < map.line - (map.line % size))
		{
			if (ft_double_case(*previous_list, **tab))
			{
				*new_list = *previous_list;
				new_list++;	
			}
		}
		previous_list++;
	}
	*new_list = '\0';
}

t_doubled	*ft_retrieve_not_doubled(t_doubled *previous_list, int size)
{
	int			line;
	int			column;
	t_doubled	*new_list;
// malloc
	new_list = malloc(sizeof(*new_list) * ft_length(previous_list));
	while (*previous_list)
	{
		if ((*previous_list).line % size != 0 && (*previous_list).column % size != 0 && (*previous_list).column < map.column - (map.column % size) && (*previous_list).line < map.line - (map.line % size))
		{
			if (ft_double_case(*previous_list, **tab))
			{
				*new_list = *previous_list;
				new_list++;	
			}
		}
		previous_list++;
	}
	*new_list = '\0';
}
