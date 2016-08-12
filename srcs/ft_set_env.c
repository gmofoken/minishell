/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 11:55:41 by gmofoken          #+#    #+#             */
/*   Updated: 2016/07/10 15:17:52 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char			*sep(char *s)
{
	char	*prt;
	int		i;

	i = 0;
	prt = (char *)malloc(sizeof(ft_strlen(s)));
	while (s[i] != '=')
	{
		prt[i] = s[i];
		i++;
	}
	prt[i] = '\0';
	return (prt);
}

static char		**change(char *arg, char **envp)
{
	int		i;
	int		b;

	i = 0;
	b = 1;
	while (envp[i] && b != 0)
	{
		if (ft_strcmp(sep(arg), sep(envp[i])) == 0)
			b = 0;
		i++;
	}
	i--;
	envp[i] = arg;
	return (envp);
}

int				exists(char *arg, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(sep(arg), sep(envp[i])) == 0)
			return (0);
		ft_putchar('X');
		i++;
	}
	return (1);
}

char			**ft_set_env(char **args, char **envp)
{
	int		i;

	i = 0;
	if (exists(args[1], envp) == 0)
		envp = change(args[1], envp);
	else
	{
		ft_putchar('X');
		while (envp[i])
			i++;
		i--;
		ft_putstr(envp[i]);
	}
	return (envp);
}
