/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 16:15:56 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/19 09:13:02 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static int	o_args(char **args, int b, char **envp)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(args[0], "env") == 0 || ft_strcmp(args[0], "setenv")
			== 0 || ft_strcmp(args[0], "unsetenv") == 0)
		env_mod(args, envp);
	else if (ft_strcmp(args[0], "cd") == 0)
		b = ft_cd(args, envp);
	else
		b = 2;
	return (b);
}

void		launch_s(char **envp)
{
	char	*line;
	char	**args;
	int		b;

	b = 1;
	ft_putstr("\t\t\t\tWELCOME TO THE KG_SHELL V1.0 \n\n\n");
	while (b != 0)
	{
		ft_putstr("KG_SHELL$ ");
		line = ft_epur_str(ft_get_line());
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
	}
}
