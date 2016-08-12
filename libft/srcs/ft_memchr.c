/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 12:09:08 by gmofoken          #+#    #+#             */
/*   Updated: 2016/05/15 12:09:43 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char d;
	char *s1;

	s1 = (char *)s;
	d = (unsigned char)c;
	while (n--)
	{
		if (*s1 == d)
			return (s1);
		s1++;
	}
	return (0);
}
