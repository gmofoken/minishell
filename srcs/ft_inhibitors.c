/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inhibitors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 08:35:59 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/11 13:41:29 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char		*ft_line(char c, int *b)
{
	char	*line;
	char	*str;
	int		i;

	line = ft_strtrim(ft_get_line());
	i = 0;
	if (ft_even_odd_s(line, c) == 1)
	{
		str = (char*)malloc(sizeof(char) * ft_strlen(line));
		while (line[i] != c)
		{
			str[i] = line[i];
			i++;
		}
		str[i] = '\0';
		free(line);
		*b = 0;
		return (str);
	}
	return (line);
}

static char		**ft_n_a_br(char **new_args, char c, int i)
{
	char	*line;
	int		b;

	b = 1;
	while (b != 0)
	{
		ft_putchar('>');
		line = ft_line(c, &b);
		new_args[i++] = line;
	}
	new_args[i] = NULL;
	return (new_args);
}

static char		**ft_new_args(char **args, char c)
{
	char	**new_args;
	int		i;

	i = 0;
	if (!(new_args = (char**)malloc(sizeof(*new_args) * 11)))
		return (NULL);
	if (ft_len(args) > 0)
	{
		while (ft_even_odd_s(args[i], c) == 0)
		{
			new_args[i] = args[i];
			i++;
		}
	}
	return (ft_n_a_br(new_args, c, i));
}

char			**ft_inhibitors_quo(char **args)
{
	char	c;
	char	**new_args;

	if (ft_even_odd(args, '"') == 1)
		c = '"';
	else
		c = '\'';
	new_args = ft_new_args(args, c);
	ft_2d_free(args);
	return (new_args);
}
