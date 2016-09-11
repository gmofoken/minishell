/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:34:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/11 13:57:22 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char		*env_attr(char **envp, char *attr)
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

char		*unique_dir(char *arg, char **env)
{
	char	*str;

	str = ft_strjoin(env_attr(env, "HOME"), ft_strstr(arg, "/"));
	return (str);
}

static void	travel(char **env, char *dir, char **args)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strcmp(dir, "OLD") == 0)
	{
		ft_putendl(env_attr(env, "OLDPWD"));
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", env_attr(env, "OLDPWD")), env);
		ft_setenv(tmp, env);
	}
	else if (ft_strcmp(dir, "HOME") == 0)
	{
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", env_attr(env, "HOME")), env);
		ft_setenv(tmp, env);
	}
	else if (ft_strcmp(dir, unique_dir(args[1], env)) == 0)
	{
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", unique_dir(args[1], env)), env);
		ft_setenv(tmp, env);
	}
	free(tmp);
}

void		ft_cd_fnl(char **args)
{
	int		i;
	char	*s;

	i = chdir(args[1]);
	s = ft_strjoin("cd: no such file or directory: ", args[1]);
	if (i != 0)
		ft_putendl(s);
	free(s);
}

int			ft_cd(char **args, char **env)
{
	int		i;

	i = 0;
	if (ft_len(args) > 1 && ft_strcmp(args[1], "?") == 0)
		ft_putendl("zsh: no matches found: ?");
	else if (ft_len(args) > 1 && ft_strncmp(args[1], "~/", 2) == 0)
	{
		i = chdir(unique_dir(args[1], env));
		if (i == 0)
			travel(env, unique_dir(args[1], env), args);
	}
	else if (ft_len(args) == 1 || ft_strcmp(args[1], "~") == 0)
	{
		chdir(env_attr(env, "HOME"));
		travel(env, "HOME", args);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		chdir(env_attr(env, "OLDPWD"));
		travel(env, "OLD", args);
	}
	else
		ft_cd_fnl(args);
	return (1);
}
