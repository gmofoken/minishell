/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 13:37:35 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 22:26:04 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = (ft_strlen(s) - 1);
	str = ft_strnew(sizeof(s));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j--;
	}
	while (i <= j)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[i] = '\0';
	return (str);
}
