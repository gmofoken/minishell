/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 13:20:24 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/11 13:39:14 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int		ft_even_odd(char **args, char c)
{
	int		i;
	int		j;
	int		even;

	i = 0;
	even = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
			if (args[i][j++] == c)
				even++;
		i++;
	}
	if ((even % 2) == 0)
		return (0);
	return (1);
}

int		ft_even_odd_s(char *arg, char c)
{
	int		i;
	int		even;

	i = 0;
	even = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == c)
			even++;
		i++;
	}
	if ((even % 2) == 0)
		return (0);
	return (1);
}
