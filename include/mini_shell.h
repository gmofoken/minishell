/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:39:22 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 15:31:51 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

void		launch_s(char **envp);
char		*ft_get_line(void);
void		exe(char **args, char **envp);
char		*ft_path_finder(char **p, char **n);
int			env_mod(char **args, char **envp);
char		**ft_set_env(char **args, char **envp);
int			ft_cd(char **args, char **envp);

#endif
