# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 18:03:57 by gmofoken          #+#    #+#              #
#    Updated: 2016/09/11 13:24:39 by gmofoken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = srcs/exe.c srcs/ft_path_finder.c srcs/get_line.c srcs/l_shell.c \
          srcs/main.c srcs/env_module.c srcs/ft_set_env.c srcs/ft_cd.c \
		  srcs/ft_echo.c srcs/ft_putecho.c srcs/ft_do_e.c srcs/ft_unsetenv.c \
		 srcs/ft_echo_quo.c srcs/ft_inhibitors.c srcs/ft_odds.c 

HEADER = -I include

LFLAGS = -L./libft/ -lft

FLAGS = -o minishell -Wall -Werror -Wextra

all:
	@make -C libft/
	@gcc $(FLAGS) $(SOURCES) $(HEADER) $(LFLAGS)

clean:
	@rm $(NAME)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all
