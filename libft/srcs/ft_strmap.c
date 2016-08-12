/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:33:58 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/09 18:30:53 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, void (*f)(char))
{
	char	*str;

	str = ft_memalloc(sizeof(s));
	while (*s)
	{
		*str++ = *s++;
	}
	*str = '\0';
	return (str);
}
