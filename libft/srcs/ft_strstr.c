/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:43:29 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/09 18:10:46 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	if (needle == NULL)
		return ((char *)haystack);
	b = ft_strlen(needle);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j])
			{
				j++;
				i++;
				if (j == b)
					return ((char *)&haystack[i - j]);
			}
		}
		i++;
	}
	return ("\0");
}
