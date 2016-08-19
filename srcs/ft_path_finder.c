/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:38:28 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/19 09:18:48 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char		**split_path(char *p)
{
	return (ft_strsplit(&p[5], ':'));
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
	while (dir[i] != 0)
	{
		d = ft_strjoin(dir[i], "/");
		tmp = ft_strjoin(d, *n);
		free(d);
		d = tmp;
		if (access(d, F_OK) == 0)
			return (d);
		i++;
	}
	ft_putendl(ft_strjoin("zsh: command not found: ", *n));
	return (NULL);
}
