/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 16:15:56 by gmofoken          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:29 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static int	o_args(char **args, int b, char **envp)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(args[0], "env") == 0 || ft_strcmp(args[0], "setenv")
			== 0 || ft_strcmp(args[0], "unsetenv") == 0)
	{
		env_mod(args, envp);
		b = 1;
	}
	else if (ft_strcmp(args[0], "cd") == 0)
		b = ft_cd(args, envp);
	else if (ft_even_odd(args, '\'') == 1 || ft_even_odd(args, '"') == 1)
		args = ft_inhibitors_quo(args);
	else
		b = 2;
	return (b);
}

void		cleaner(char *line, char **args)
{
	int		i;

	i = 0;
	free(line);
	while (args[i++])
		free(args[i]);
	free(args);
}



void		launch_s(char **envp)
{
	char	*line;
	char	**args;
	int		b;
	char	*temp;

	b = 1;
	while (b != 0)
	{
		ft_putstr("$ ");
		temp = ft_get_line();
		line = ft_epur_str(temp);
		free(temp);
		args = ft_strsplit(line, ' ');
		if (ft_strlen(line) > 0 && args[0] != NULL)
		{
			if (ft_strcmp(args[0], "exit") == 0)
				b = 0;
			else
				b = o_args(args, b, envp);
			if (b == 2)
				exe(args, envp);
		}
		cleaner(line, args);
	}
}
