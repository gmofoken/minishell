/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 23:20:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/17 15:04:50 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
static int	ft_len(char **args)
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
	while (args[i] != '\0')
	{
		ft_putstr(args[i]);
		if (i != j - 1)
			ft_putchar(' ');
		i++;
	}
}

static int ft_stop(char *s)
{
	char	*tmp;
	int	l;
	int	i;

	l = 0;
	i = 0;
	tmp = ft_strstr(s, "\\c");
	if (tmp != NULL)
		i = ft_strlen(tmp);
	if (i > 0)	
		l = (ft_strlen(s) - i);
	else
		return (ft_strlen(s));
	return (l - 1);
}

static void ft_e(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (args[j][i] == '-')
		j++;
	while (args[j++] != '\0')
	{
		while (i < ft_stop(args[j]) && args[j][i] != '\0')
		{
			ft_putchar(args[j][i]);
			i++;
		}
	}
}

void		ft_echo(char **args)
{
	int		i;
	int		n;
	int		b;

	n = 0;
	i = 0;
	b = 3;
	ft_putnbr(ft_len(args));
	if (ft_len(args) > 0 && args[1][0] == '-')
		while (args[1][i++])
		{
			if (args[1][i] == 'n')
				n = 1;
			else if (args[1][i] == 'e')
				b = 0;
		}
	else
		b = 0;
	if (b == 1)
		ft_cap_e(args);
	else if (b == 0)
		ft_e(args);
	if (n == 1)
		ft_putchar('$');
	ft_putchar('\n');
}
