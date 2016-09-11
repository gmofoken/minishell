/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_quo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 10:28:30 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/03 09:23:44 by gmofoken         ###   ########.fr       */
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

char		*ft_first_arg(char **args)
{
	char		*arg;
	int			i;

	i = 1;
	arg = args[i++];
	while (ft_len(args) > i)
	{
		arg = ft_strjoin(arg, args[i]);
		i++;
	}
	return (arg);
}

static char		**ft_new_args(char **args)
{
	int		b;
	char	*line;
	char	**new_args;
	int		i;
	int		j;

	b = 1;
	i = 0;
	if (!(new_args = (char**)malloc(sizeof(*new_args) * 11)))
		return (NULL);
	new_args[i] = ft_strdup(args[i]);
	i++;
	new_args[i++] = ft_first_arg(args);
	while (b != 0)
	{
		ft_putstr("dquote> ");
		line = ft_strtrim(ft_get_line());
		new_args[i - 1] = ft_strjoin(new_args[i - 1], "\n");
		new_args[i++] = line;
		j = 0;
		while (line[j++] != '\0')
			if (ft_even_odd_s(line, '"') == 1)
				b = 0;
	}
	new_args[i] = NULL;
	return (new_args);
}

char			**ft_echo_quo(char **args, int *e)
{
	char	**new_args;

	if (ft_even_odd(args, '"') == 1)
	{
		*e = 1;
		new_args = ft_new_args(args);
		return (new_args);
	}
	return (args);
}
