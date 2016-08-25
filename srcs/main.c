/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:57:26 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/25 15:04:08 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	main(void)
{
	extern char	**environ;

	execve("clear", (char **)"clear", environ);
	launch_s(environ);
	return (0);
}
