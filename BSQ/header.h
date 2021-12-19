/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:45:04 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/29 21:31:06 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <libc.h>

typedef struct s_quares_candidates
{
	int	line;
	int	column;
	int	size;
} t_candidates;
typedef struct s_info
{
    int line;
    int column;
	char obstacle;
	char empty;
	char full;
} t_info;

typedef struct s_coordo
{
	int	x;
	int	y;
	int	size;
}	t_coordo;

typedef struct	s_doubled
{
	int	line;
	int	column;
} t_doubled;
typedef struct	s_expansion;
{
	int	up;
	int	down;
	int	left;
	int	right;
} t_expansion;
int	ft_power_two(char exponent);
int	ft_length_doub(t_doubled *list);
int	ft_double_case(t_doubled *position, char **tab);
t_doubled	*ft_double_grid(char **tab, t_doubled *previous_list, int size, t_info map);
t_doubled	*ft_retrieve_not_doubled(t_doubled *previous_list);
void	ft_stdin(void);
void	ft_parse_file(char *map_path);
int	ft_file_size(char *dict_path);
void	ft_total(char *str_map);
int	ft_full_find(char *str_map);
int	ft_empty_find(char *str_map);
int	ft_obstacle_find(char *str_map);
int	ft_column_number(char *str_map);
int	ft_line_number(char *str_map);
char *ft_str_map_next_line(char *str_map);
 char **ft_create_maptab(char *str_map_no_first_line, t_info info);
 void ft_sort_map( char **tab_map, t_info info, t_coordo coordo);
int ft_min(int a, int b);
t_candidates    ft_expand_candidate(t_doubled *candidate, unsigned char **tab, t_info map, t_candidates *prospect);
t_candidates    ft_expa
int	ft_min(int a, int b);
t_candidates	ft_expand_candidate(t_doubled *candidate, unsigned char **tab, t_info map, t_candidates *prospect);
t_candidates	ft_expand_candidates(t_doubled *list, unsigned char **tab, t_info map);
int ft_length_cand(t_candidates*list);
int	ft_grid_alignement(int position_on_line, int distance_to_border);
int	ft_line_expansion(t_candidates *element, unsigned char **tab, t_info map, int up);
int	ft_column_expansion(t_candidates *element, unsigned char **tab, t_info map, int left);

#endif

