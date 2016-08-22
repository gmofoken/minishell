/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 23:20:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/22 09:01:37 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int			ft_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	ft_cap_e(char **args)
{
	int		i;
	int		j;

	i = 2;
	j = i;
	while (args[j])
		j++;
	if (args[1][0] != '-')
		i++;
	while (args[i])
	{
		ft_putecho(args[i]);
		if (i != j - 1)
			ft_putchar(' ');
		i++;
	}
}

static void	ft_e(char **args)
{
	int	i;
	int	b;

	i = 1;
	b = 1;
	if (args[1][0] == '-')
		i++;
	while (args[i] && b != 0)
	{
		b = ft_do_e(args[i]);
		if (i < ft_len(args) - 1)
			ft_putchar(' ');
		i++;
	}
}

void		ft_echo_br(int b, char **args)
{
	if (b == 1)
		ft_cap_e(args);
	if (b == 0)
		ft_e(args);
}

void		ft_echo(char **args)
{
	int		i;
	int		n;
	int		b;

	n = 0;
	i = 0;
	b = 1;
	if (args[1] != NULL || args[1] != '\0')
	{
		if (ft_len(args) > 1 || ft_strncmp(args[1], "-e", 2) == 0)
		{
			while (args[1][i++])
			{
				if (args[1][i] == 'n')
					n = 1;
				else if (args[1][i] == 'e' || args[1][0] != '-')
					b = 0;
			}
		}
		ft_echo_br(b, args);
	}
	if (n == 1)
		ft_putchar('$');
	ft_putchar('\n');
}
