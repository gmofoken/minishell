/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:39:22 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/11 10:47:52 by gmofoken         ###   ########.fr       */
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
void		ft_setenv(char *arg, char **env);
int			ft_cd(char **args, char **envp);
void		ft_echo(char **args);
void		ft_putecho(char *s);
int			ft_len(char **args);
int			ft_do_e(char *arg);
void		ft_unsetenv(char **env, char *str);
void		ft_resetenv(char **env, char *str);
char		*ft_realloc(char *str, char *str2);
void		ft_execute_env(char **env);
void		ft_2d_free(char **arg);
char		**ft_echo_quo(char **args, int *e);
int			ft_even_odd(char **args, char c);
char		**ft_inhibitors_quo(char **args);
char		*ft_first_arg(char **args);
int			ft_even_odd_s(char *arg, char c);

#endif
