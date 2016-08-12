/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 17:51:18 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/10 16:27:06 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		n;
	int		i;
	char	*temp;

	i = 0;
	neg = 1;
	n = 0;
	temp = ft_strtrim(str);
	if (temp[i] == 45)
	{
		neg = -1;
		i++;
	}
	while (temp[i])
	{
		if (temp[i] >= 48 && temp[i] <= 57)
			n = (n * 10) + temp[i] - '0';
		i++;
	}
	return (n * neg);
}
