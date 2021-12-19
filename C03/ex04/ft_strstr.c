/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:06:23 by audreyer          #+#    #+#             */
/*   Updated: 2021/09/27 18:16:59 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	b;
	int	i;
	int	mem;

	i = 0;
	if (to_find[0] == 0 && str[0] == 0)
		return (to_find);
	while (str[i])
	{
		b = 0;
		mem = i;
		while (str[i] == to_find[b] && to_find[b])
		{
			i++;
			b++;
		}
		if (to_find[b] == 0)
			return (&str[mem]);
		i = mem;
		i++;
	}
	return (0);
}
