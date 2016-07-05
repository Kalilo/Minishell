#include "minishell.h"

void	free2d(char arr[][])
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
	if (E_EN != NULL)
		free2d(E_EN);
	if (E_LI != NULL)
		free(E_LI);
	if (E_A != NULL)
		free(E_A);
	exit(1);
}