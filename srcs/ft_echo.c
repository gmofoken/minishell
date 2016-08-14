/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 23:20:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/14 16:00:48 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	ft_cap_e(char **args)
{
	int		i;
	int		j;

	i = 2;
	j = i;
	while (args[j])
		j++;
	while (args[i] != '\0')
	{
		ft_putstr(args[i]);
		if (i != j - 1)
			ft_putchar(' ');
		i++;
	}
}

void		ft_echo(char **args)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (args[1][i++])
	{
		if (args[1][i] == '-' )
			i++;
		if (args[1][i] == 'n')
			n = 1;
		else if (args[1][i] == 'E')
		{
			ft_cap_e(args);
		}
		//else
			//ft_cap_e(args);
	}
	if (n == 1)
		ft_putchar('$');
	ft_putchar('\n');
}
