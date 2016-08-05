#include "../includes/minishell.h"

void	ke_jump_left(t_env *env)
{
	int		k;

	while ((k = ft_strlen(I_L1) - 1) >= 0 && I_L1[k] != '\t'
			&& I_L2[k] != ' ')
		ke_left(env);	
}

void	ke_jump_right(t_env *env)
{
	int		k;

	k = -1;
	while (I_L2 && I_L2[k + 1] && (I_L2[k + 1] == '\t' ||
		I_L2[k + 1] == ' '))
		k++; 
	while (I_L2 && I_L2[++k] && I_L2[k] != '\t' &&
			I_L2[k] != ' ')
		ke_right(env);
}
