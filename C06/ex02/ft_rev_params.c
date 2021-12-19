/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:51:58 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/20 17:35:13 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		j++;
		i = 0;
		write(1, "\n", 1);
	}
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = argc - 1;
	if (argc == 1)
		return (0);
	while (i < j)
	{
		ft_swap(&argv[i], &argv[j]);
		i++;
		j--;
	}
	ft_print(argv);
	return (0);
}
