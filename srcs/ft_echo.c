/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 23:20:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/01 14:52:09 by gmofoken         ###   ########.fr       */
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

int			ft_echo_branch(char **e_args, int n, int b)
{
	int		i;

	i = 0;
	if (ft_len(e_args) > 1 || ft_strncmp(e_args[1], "-e", 2) == 0)
	{
		while (e_args[1][i++])
		{
			if (e_args[1][i] == 'n')
				n = 1;
			else if (e_args[1][i] == 'e' || e_args[1][0] != '-')
				b = 0;
		}
	}
	ft_echo_br(b, e_args);
	return (n);
}

void		ft_echo(char **args)
{
	int		i;
	int		n;
	int		b;
	//int		echo;
	//char	**e_args;

	n = 0;
	i = 0;
	b = 1;
	//args = NULL;
	ft_putendl("echo#1");
	ft_echo_quo(&args);
	ft_putendl("echo#2");
	if (args[1] != NULL || args[1] != '\0')
		n = ft_echo_branch(args, n, b);
	if (n == 1)
		ft_putchar('$');
	ft_putchar('\n');
}
