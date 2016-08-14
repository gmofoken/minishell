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

static void ft_e()
{
	ft_putstr("KJHS MBNS");
}

void		ft_echo(char **args)
{
	int		i;
	int		n;
	int		b;

	n = 0;
	i = 1;
	b = 1;
	if (args[1][0] == '-')
		while (args[1][i++])
		{
			if (args[1][i] == 'n')
				n = 1;
			if (args[1][i] == 'e')
				b = 0;
		}
	else
		b = 2;
	ft_putnbr(b);
	if (b == 1)
		ft_cap_e(args);
	else if (b == 0)
		ft_e();
	if (n == 1)
		ft_putchar('$');
	ft_putchar('\n');
}
