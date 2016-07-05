/*
 *	Things we still need:
 *		int		env_valid(char *s);
 *		void	error(int i);
 */
#include "../includes/minishell.h"

void	set_env(t_env *env, char *s)
{
	char	*temp;
	int		check;

	if (check == env_valid(s))
	{
		temp = env->a;
		env->a = ft_strjoin(env->a, s);
		free(temp);
	}
	else
		error(0);
	if (check == 2)
		command(env, ft_strchr(s, ' '));
}
