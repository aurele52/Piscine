/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:55:53 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/19 20:55:57 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_arg(int argc, char **argv)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (((argv[1][i] < '1' || argv[1][i] > '4')
					&& argv[1][i] != ' '))
			return (0);
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
			word++;
		i++;
	}
	if (i != 31 || word != 16)
		return (0);
	return (1);
}
