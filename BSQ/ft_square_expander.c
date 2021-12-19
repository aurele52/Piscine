/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athierry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:36:07 by athierry          #+#    #+#             */
/*   Updated: 2021/09/29 21:46:13 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// function to compute the length of a list of candidates
int ft_length_cand(t_candidates *list)
{
	int	index;

	index = 0;
	while(*list++)
		index++;
	return (index);
}

// function to compute what is the biggest number above a given cell
int	ft_grid_alignement(int position_on_line, int distance_to_border)
{
	int	i;
	int	exponent;
	
	i = 0;
	exponent = 1;
	while (exponent <= position_on_line)
	{
		if (position_on_line % exponent == 0)
			i = exponent;
		exponent *= 2;
	}
}

// function to figure out how much of space is available above (up = 1) or bellow (up = -1) a given line
int	ft_line_expansion(t_candidates *element, unsigned char **tab, t_info map, int up)
{
	int				potential_size;
	int				min;
	int				size;
	int				index;
	unsigned char	**position;

	index = 0;
	**position = *(*(tab + *element.line) + *element.column);
	if (!(*element.size))
		size = ft_power_two(**position);
	else
		size = *element.size;
	while (index <= size)
	{
			potential_size = ft_grid_alignement(*element.column);
			while (potential_size)
			{
				if (ft_power_two(*(*(tab + *element.line + up * potential_size) + (*element.column))) == potential_size)
				{
					if (potential_size < min)
						min = potential_size;
					index += potential_size;
					potential_size = 0;
				}	
				potential_size /=2;
			}
	}
	return (min);
}

// function to figure out how much space is available on the left (left = -1) or on the right (left = 1) of a given column
int	ft_column_expansion(t_candidates *element, unsigned char **tab, t_info map, int left)
{
	int				potential_size;
	int				min;
	int				size;
	int				index;
	unsigned char	**position;

	min = 0;
	index = 0;
	**position = *(*(tab + *element.line) + *element.column)
	size = ft_power_two(**position);
	while (index <= size)
	{
			potential_size = ft_grid_alignment(*element.line);
			while (potential_size)
			{
				if (ft_power_two(*(*(tab + *element.line) + *element.column + left * potential_size)) == potential_size)
				{
					if (potential_size < min)
						min = potential_size;
					index += potential_size;
					potential_size = 0;
				}	
				potential_size /=2;
			}
	}
	return (min);
}

// structure to register the possible extansions of a square

// function min of two integers
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

// function to extend a squar as much as possible 
t_candidates	ft_expand_candidate(t_doubled *candidate, unsigned char **tab, t_info map, t_candidates *prospect)
{
	t_expansion	candidate_expansion;
	int	ret;
	int	expanded;

	expanded = 1;
	if (!(*prospect.size))
	{
		*prospect.line = *candidate.line;
		*prospect.column = *candidate.column;
		*prospect.size = ft_power_two(  *(*(tab + *candidate.line) + *candidate.column);
	}
	while (expanded)
	{
		candidate_expansion.up = ft_line_expansion(*candidate, **tab, map, -1);
		candidate_expansion.down = ft_line_expansion(*candidate, **tab, map, 1);
		candidate_expansion.right = ft_column_expansion(*candidate, **tab, map, 1);
		candidate_expansion.left = ft_column_expansion(*candidate, **tab, map, -1);
		expanded = 0;
		if (candidate_expansion.left && candidate_expansion.up)
		{
			ret = ft_min(candidate_expansion.left, candidate_expansion.up);
			*candidate.line -= ret;
			*candidate.column -= ret;
			candidate_expansion.up -= ret;
			candidate_expansion.left -= ret;
			*prospect.size += ret;
			expanded = 1;
		}
		if (candidate_expansion.left && candidate_expansion.down)
		{
			ret = ft_min(candidate_expansion.left, candidate.expansion.down);
			*candidate.column -= ret;
			*candidate_expansion.left -= ret;
			*candidate_expansion.down -= ret;
			*prospect.size += ret;
			expanded = 1;
		}
		if (candidate_expansion.up && candidate_expansion.right)
		{
			ret = ft_min(candidate_expansion.up, candidate_expansion.right);
			*candidate.line -= ret;
			*candidate_expansion.up -= ret;
			*candidate_expansion.right -= ret;
			prospect.size += ret;
			expanded = 1;
		}
		if (candidate_expansion.right && candidate_expansion.down)
		{
			ret = ft_min(candidate_expansion.right, candidate_expansion.down);
			*candidate_expansion.right -= ret;
			*candidate_expansion.down -= ret;
			prospect.size += ret;
			expanded = 1;
		}
	}
}

// function to expand all squares in the list
t_candidates	ft_expand_candidates(t_doubled *list, unsigned char **tab, t_info map)
{
	t_candidates	*candidate_list;
	t_expansion		*expansions;

	candidate_list = malloc(sizeof(*candidate_list) * ft_length_doub(*list) + 1);
	expansions = malloc(sizeof(*expansions) * ft_length_doub(*list) + 1);
	while (*list)
		ft_expand_candidate(*list, tab, map, candidate_list);
}
