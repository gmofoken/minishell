/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:06:04 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/11 12:10:19 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = ft_strlen(little);
	while (i <= len)
	{
		k = 0;
		if (big[i] == little[k])
		{
			while (big[i] == little[i])
			{
				k++;
				i++;
				if (k == j)
					return ((char *)&big[i - j]);
			}
		}
		i++;
	}
	return (NULL);
}
