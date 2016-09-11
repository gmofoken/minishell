#include "mini_shell.h"

static char	**ft_new_args(char **args, char c)
{
	char	**new_args;
	int	i;
	int	b;
	char	*line;
	int	j;

	b = 1;
	i = 0;
	if (!(new_args = (char**)malloc(sizeof(*new_args) * 11)))
		return (NULL);
	if (ft_len(args) > 1)
		new_args[i++] = ft_first_arg(args);
	while (b != 0)
	{
		ft_putchar('>');
		line = ft_strtrim(ft_get_line());
		new_args[i++] = line;
		j = 0;
		while (line[j++] != '\0')
			if (ft_even_odd_s(line, c) == 1)
				b = 0;
	}
	new_args[i] = NULL;
	return (new_args);
}

void		ft_inhibitors_quo(char **args)
{
	char	c;
	char	**new_args;

	if (ft_even_odd(args, '"') == 1)
		c = '"';
	else
		c = '\'';
	new_args = ft_new_args(args, c);
	while (*new_args != NULL)
	{
		ft_putendl(*new_args);
		new_args++;
	}
}
