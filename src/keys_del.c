#include "../includes/minishell.h"

void	ke_del(t_env *env)
{
	char	*k;

	if (I_L2 == NULL || ft_strlen(I_L2) == 0)
		return ;
	k = ft_str_inc_dup((I_L2));
	I_C2 = ft_strlen(I_L2) - 1;//I_C2 = (ft_strlen(I_L2) != 0) ? ft_strlen(I_L2) - 1 : 0;
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = k;
}
