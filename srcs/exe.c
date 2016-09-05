/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:16:59 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 12:53:06 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	exe(char **args, char **envp)
{
	pid_t		pid;
	char		*dir;
	int			i;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		dir = ft_path_finder(envp, args);
		if (dir == NULL)
			exit(0);
		i = execve(dir, args, envp);
		if (i != 0)
			ft_putstr("ERROR");
		free(dir);
	}
	else if (pid < 0)
		ft_putstr("WORLD COMING TO AN END!!!! RUN!!!!!!!!!!!!");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
}
