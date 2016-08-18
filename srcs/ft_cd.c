/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:34:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/17 17:19:30 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	*env_attr(char **envp, char *attr)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (envp[i] && b == 0)
	{
		if (ft_strncmp(envp[i], attr, ft_strlen(attr)) == 0)
			b = 1;
		i++;
	}
	i--;
	return (ft_strstr(envp[i], "/"));
}

char	*unique_dir(char *arg, char **env)
{
	return (ft_strjoin(env_attr(env, "HOME"), ft_strstr(arg, "/")));
}

int	ft_cd(char **args, char **env)
{
	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (ft_strncmp(args[1], "~/", 2) == 0)
			chdir(unique_dir(args[1], env));
		else if (!args[1] || ft_strcmp(args[1], "~") == 0)
			chdir(env_attr(env, "HOME"));
		else if (ft_strcmp(args[1], "-") == 0)
			chdir(env_attr(env, "OLDPWD"));
		else
			chdir(args[1]);
	}
	return (1);
}
