/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 18:40:50 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 22:16:06 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_str(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		b;

	str = ft_strnew(sizeof(s));
	i = 0;
	j = 0;
	b = 0;
	while (s != NULL && ft_strlen(s) > 0 && s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t')
		{
			b = 1;
			i++;
		}
		if (b == 1)
			str[j++] = ' ';
		if (s[i] != ' ' || s[i] != '\t')
		{
			str[j++] = s[i++];
			b = 0;
		}
	}
	return (ft_strtrim(str));
}
