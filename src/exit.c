#include "minishell.h"

void		free2d(char arr[][])
{
	int		k;
	
	k = 0;
	while (str[k] != NULL)
	{
		free(str[k]);
		k++;
	}
	free(arr);
}

void	exit_prog(t_env env)
{
}