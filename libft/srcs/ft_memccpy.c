/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:58:59 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/09 16:07:44 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int						i;
	unsigned char			*tmp1;
	const unsigned char		*tmp2;

	i = 0;
	tmp1 = s1;
	tmp2 = s2;
	while (n > 0)
	{
		tmp1[i] = tmp2[i];
		if (tmp1[i] == (unsigned char)c)
			return (s1 + 1 + i);
		i++;
		n--;
	}
	return (NULL);
}
