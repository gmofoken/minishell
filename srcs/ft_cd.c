/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:34:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/18 16:45:15 by gmofoken         ###   ########.fr       */
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

static void	travel(char **env)
{
	char	*tmp;
	tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
	ft_setenv(ft_strjoin("PWD=", env_attr(env, "OLDPWD")), env);
	ft_setenv(tmp, env);
}

int	ft_cd(char **args, char **env)
{
	if (args[1] == NULL || args[1] =='\0' || ft_strcmp(args[1], "~") == 0)
		chdir(env_attr(env, "HOME"));
	else if (ft_strncmp(args[1], "~/", 2) == 0)
		chdir(unique_dir(args[1], env));
	else if (ft_strcmp(args[1], "-") == 0)
	{
		chdir(env_attr(env, "OLDPWD"));
		travel(env);
	}
	else
		chdir(args[1]);
	return (1);
}
