/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:50:19 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/14 01:07:47 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_capitalize(char *str, int i, int b)
{
	while (str[i])
	{
		if (((str[i] <= 'z' && str[i] >= 'a')
				|| (str[i] <= '9' && str[i] >= '0')) && b == 0 )
		{
			b = 1;
			if (str[i] <= 'z' && str[i] >= 'a')
				str[i] = str[i] - 'a' + 'A';
			i++;
		}	
		else
		{
			if ((!(str[i] >= 'a' && str[i] <= 'z'))
				&& (!(str[i] >= 'A' && str[i] <= 'Z'))
				&& (!(str[i] >= '0' && str[i] <= '9')))
				b = 0;
			i++;
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	i = 0;
	return (ft_capitalize(str, i, b));
}
