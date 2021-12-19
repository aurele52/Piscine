/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaveux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:56:23 by cdaveux           #+#    #+#             */
/*   Updated: 2021/09/26 21:22:36 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

void	ft_final(char *str, char *nbr);
void	ft_suite(char *str, char *nb);
void	ft_write(char *str, int *written, int i, int j);
void	ft_num(char *str, char a, int j);
void	ft_printhundred(char *str);
void	ft_foisdix(char *str, char d, int j);
void	ft_dizaine(char *str, char *nbr, int j, int i);
void	ft_printsep1(char *str, int zero, char *nbr, int j);
void	ft_printsep0(char *str, int zero, char *nbr, int j);
void	ft_printsep2(char *str, int zero, char *nbr, int j);
void	ft_sep_inc(int *a, int *i);
void	ft_separateur(char *str, char *nbr);
void	ft_print_sep_skip(char *str, int *i, int zero, int *a);
void	ft_call_display(char *dict, char *nbr);
int		ft_file_size(char *dict_path);
int		ft_checktab(char *str);
int		ft_parse_file(char *dict_path, char *nb);
int		ft_intlen(char *nb);
int		ft_skip(char *str, int i);
int		ft_triplet(char *str, char *nbr, int i);
int		ft_check_arg(char *argv1);

#endif
