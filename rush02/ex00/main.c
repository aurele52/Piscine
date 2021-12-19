/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:48:46 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/26 21:21:07 by cdaveux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libc.h>

int	ft_parse_file(char *dict_path, char *nb);
int	ft_check_arg(char *argv1);

int	ft_check_arg(char *argv1)
{
	int	i;

	i = 0;
	while ((argv1[i] >= 9 && argv1[i] <= 13) || argv1[i] == 32)
		i++;
	if (argv1[0] == '0' && argv1[i + 1])
	{
		while (argv1[i] == '0')
			i++;
	}
	while (argv1[i] >= '0' && argv1[i] <= '9')
		i++;
	if (i >= 38)
		return (-1);
	if ((argv1[i] < '0' || argv1[i] > '9') && argv1[i] != '\0')
		return (-1);
	return (1);
}

char	*ft_convert(char *nbr)
{	
	int	i;

	i = 0;
	while ((nbr[0] >= 9 && nbr[0] <= 13) || nbr[0] == 32)
		nbr++;
	while (nbr[0] == '0' && (nbr[1] >= '0' && nbr[1] <= '9'))
		nbr++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
		i++;
	nbr[i] = 0;
	return (nbr);
}

void	ft_call_display(char *dict, char *nbr)
{
	nbr = ft_convert(nbr);
	if (ft_parse_file(dict, nbr) != -1)
	{
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*dict;

	if ((argc > 3) || (argc == 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (argc == 2)
	{
		nbr = argv[1];
		dict = "numbers.dict";
	}
	else
	{
		nbr = argv[2];
		dict = argv[1];
	}
	if (ft_check_arg(nbr) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	ft_call_display(dict, nbr);
	return (0);
}
