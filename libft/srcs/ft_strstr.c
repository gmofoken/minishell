/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:43:29 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/15 17:09:46 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (needle == NULL || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strcmp(haystack, needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
