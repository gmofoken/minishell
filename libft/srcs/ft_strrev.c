/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 09:19:36 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/09 18:28:52 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (j >= 0)
	{
		str[i] = s[j];
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}
