#include "../includes/minishell.h"

int		count(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}
