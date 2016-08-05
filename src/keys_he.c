#include "../includes/minishell.h"

/*
**		Moves everything to the second string (I_L2)
*/
void	ke_home(t_env *env)
{
	char	*temp;

	temp = ft_strjoin(I_L1, I_L2);
	if (I_L1 != NULL)
		free(I_L1);
	if (I_L2 != NULL)
		free(I_L2);
	I_L1 = NULL;
	I_L2 = temp;
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}


/*
**		Moves everything to the first string (I_L1)
*/
void	ke_end(t_env *env)
{
	char	*temp;

	temp = ft_strjoin(I_L1, I_L2);
	if (I_L1 != NULL)
		free(I_L1);
	if (I_L2 != NULL)
		free(I_L2);
	I_L1 = NULL;
	I_L1 = temp;
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}
