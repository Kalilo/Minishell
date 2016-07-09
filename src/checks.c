#include "../includes/minishell.h"

int allowed_character(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (ft_memchr(AL_SYM, c, ft_strlen(AL_SYM)) != NULL)
		return (1);
	return (0);
}

int	arg_valid(char **sa, int i)
{
	int		k;
	
	k = 0;
	//while ()
	return (1);
}
