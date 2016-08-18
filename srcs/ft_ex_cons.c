#include "mini_shell.h"

static int	ft_check_flag(char c)
{
	if (c == 'b')
		return (4);
	return (0);
}

int	ft_stop(char *s)
{
	char	*tmp;
	int	i;

	i = 0;
	tmp = ft_strstr(s, "\\\\c");
	if (tmp != NULL)
		i = (ft_strlen(s) - ft_strlen(tmp));
	if (ft_strlen(s) == ft_strlen(tmp))
		i = ft_strlen(s);
	return (i);
}

int		ft_ex_cons(char *arg)
{
	int	b;
	int	i;
	int	j;
	int	l;

	b = 1;
	i = 0;
	l = ft_stop(arg);
	while (arg[i] && i < l)
	{
		j = i + 1;
		if (arg[j] != '\0' && arg[j] == '\\')
			i += ft_check_flag(arg[j + 2]);
		ft_putchar(arg[i]);
		i++;
	}
	return (b);
}
