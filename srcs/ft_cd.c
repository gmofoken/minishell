/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:34:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 23:49:27 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*home_dir(char *home)
{
	int		i;
	int		j;
	char	*h;

	i = 0;
	j = 0;
	while (home[i] != '=')
		i++;
	i++;
	h = (char *)malloc(sizeof(ft_strlen(home)));
	while (home[i])
	{
		h[j] = home[i];
		i++;
		j++;	
	}
	h[j] = '\0';
	return (h);
}

char	*home(char **envp)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (envp[i] && b == 0)
	{
		if (ft_strncmp(envp[i], "HOME", 4) == 0)
			b = 1;
		i++;
	}
	i--;
	return (home_dir(envp[i]));
}

int		ft_cd(char **args, char **envp)
{
	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (!args[1])
			chdir(home(envp));
		else
			chdir(args[1]);
	}
	return (1);
}
