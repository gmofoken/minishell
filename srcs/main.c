/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:57:26 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/03 09:22:48 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

char	**ft_env_dup(void)
{
	extern char **environ;
	char		**env;
	int			i;
	int			j;

	i = 0;
	env = (char **)malloc(sizeof(char *) * 30);
	while (environ[i] != NULL)
	{
		j = 0;
		env[i] = (char *)malloc(sizeof(char) * ft_strlen(environ[i]));
		while (environ[i][j])
		{
			env[i][j] = environ[i][j];
			j++;
		}
		env[i][j] = '\0';
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		main(void)
{
	char	**environ;

	environ = ft_env_dup();
	execve("clear", (char **)"clear", environ);
	launch_s(environ);
	return (0);
}
