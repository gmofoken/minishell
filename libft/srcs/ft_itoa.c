/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 09:19:09 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/10 16:36:18 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	char		*rep;
	long int	num;
	int			i;

	rep = "0123456789";
	if (!(s = (char *)malloc(sizeof(char))))
		return (NULL);
	i = 0;
	num = n;
	if (n < 0)
		num *= -1;
	if (n == 0)
		return ("0");
	while (num != 0)
	{
		s[i] = rep[num % 10];
		i++;
		num /= 10;
	}
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (ft_strrev(s));
}
