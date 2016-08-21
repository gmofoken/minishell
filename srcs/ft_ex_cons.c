/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_cons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 08:36:04 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/21 10:16:03 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	ft_f_v(int i)
{
	int		j;

	j = 0;
	ft_putchar('\n');
	while (j++ <= i)
		ft_putchar(' ');
}

static int	ft_check_flag(char c, int i)
{
	if (c == 'b')
		return (4);
	if (c == 'e')
		return (5);
	if (c == 'n')
	{
		ft_putchar('\n');
		return (4);
	}
	if (c == 't')
	{
		ft_putchar('\t');
		return (4);
	}
	if (c == 'f' || c == 'v')
	{
		ft_f_v(i);
		return (4);
	}
	else if (c != 'c')
	{
		ft_putchar('\\');
		return (4);
	}
	return (0);
}

int			ft_stop(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr(s, "\\c");
	if (tmp != NULL)
		i = (ft_strlen(s) - ft_strlen(tmp));
	else
		i = ft_strlen(s);
	return (i);
}

int			ft_ex_cons(char *arg)
{
	int	b;
	int	i;
	int	j;
	int	l;

	b = 1;
	i = 0;
	l = ft_stop(arg) - 1;
	if (l != (int)ft_strlen(arg) - 1)
		b = 0;
	while (arg[i] && i < l)
	{
		j = i + 1;
		if (arg[j] != '\0' && arg[j] == '\\')
		{
			if (arg[j + 2] == 'e')
				ft_putchar(arg[i]);
			i += ft_check_flag(arg[j + 2], i);
		}
		if (arg[i] == '\"')
			i++;
		else
			ft_putchar(arg[i]);
		i++;
	}
	if (arg[i] != '\\')
		ft_putchar(arg[i]);
	return (b);
}
