#include "../includes/minishell.h"

int		ft_strchr_f(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}
