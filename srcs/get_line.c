/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:19:34 by gmofoken          #+#    #+#             */
/*   Updated: 2017/01/12 14:22:52 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char		get_char(void)
{
	char	chr;

	read(0, &chr, 1);
	return (chr);
}

char		*resize_str(char *str, int size)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(size);
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	free(str);
	return (arr);
}

char			*ft_get_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		size;
	char	*temp;

	size = 128;
	(void)temp;
	line = (char *)malloc(size * sizeof(char));
	i = 0;
	while (1)
	{
		c = get_char();
		if (c == '\n' || c == '\0')
		{
			//line[i] = '\0';
			return (line);
		}
		if (size - 1 <= i)
		{
			//size = size * 2;
			//temp = resize_str(line, size);
			//line = temp;
			//free(temp);
		}
		ft_strncat(line, &c, 1);
		//line[i++] = c;
	}
	return (line);
}
