/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:38:28 by gmofoken          #+#    #+#             */
/*   Updated: 2017/01/12 16:02:21 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char		**split_path(char *p)
{
	char	**ret;

	ret = ft_strsplit(&p[5], ':');
	free(p);
	return (ret);
}

static char		*f_path(char **p)
{
	int		i;

	i = 0;
	while (p[i] != '\0')
	{
		if (ft_strncmp(p[i], "PATH", 4) == 0)
			return (p[i]);
		i++;
	}
	return (NULL);
}

void			clean_up(char **dir, char *n, char *tmp)
{
	int		i;
	
	i = 0;
	free(tmp);
	free(n);
	while (dir[i++])
		free(dir[i]);
	free(dir);
	//ft_putendl(ft_strjoin("zsh: command not found: ", n));
}

char			*ft_path_finder(char **p, char **n)
{
	char	**dir;
	char	*d;
	char	*tmp;
	char	*p_t;
	int		i;

	if (access(*n, F_OK) == 0)
		return (*n);
	p_t = f_path(p);
	dir = split_path(p_t);
	i = 0;
	if (dir == NULL)
		return (NULL);
	while (dir[i++] != 0)
	{
		d = ft_strjoin(dir[i], "/");
		tmp = ft_strjoin(d, *n);
		free(d);
		d = tmp;
		if (access(d, F_OK) == 0)
		{
			clean_up(dir, *n, tmp);
			return (d);
		}
	}
	clean_up(dir, *n, tmp);
	return (NULL);
}
