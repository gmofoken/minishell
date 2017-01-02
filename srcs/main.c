/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:57:26 by gmofoken          #+#    #+#             */
/*   Updated: 2016/12/15 13:55:33 by gmofoken         ###   ########.fr       */
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
	env = (char **)malloc(sizeof(char *) * 40);
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
	launch_s(environ);
	return (0);
}
