/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_quo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 10:28:30 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/11 13:48:12 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char			*ft_first_arg(char **args)
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

static char		**ft_n_a_br(char **new_args, int i)
{
	int		b;
	char	*line;
	int		j;

	b = 1;
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
	free(line);
	new_args[i] = NULL;
	return (new_args);
}

static char		**ft_new_args(char **args)
{
	char	**new_args;
	int		i;

	i = 0;
	if (!(new_args = (char**)malloc(sizeof(*new_args) * 11)))
		return (NULL);
	new_args[i] = ft_strdup(args[i]);
	i++;
	new_args[i++] = ft_first_arg(args);
	return (ft_n_a_br(new_args, i));
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
