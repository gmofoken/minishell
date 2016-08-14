# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 18:03:57 by gmofoken          #+#    #+#              #
#    Updated: 2016/08/14 13:28:08 by gmofoken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = srcs/exe.c srcs/ft_path_finder.c srcs/get_line.c srcs/l_shell.c \
          srcs/main.c srcs/env_module.c srcs/ft_set_env.c srcs/ft_cd.c \
		  srcs/ft_echo.c

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
