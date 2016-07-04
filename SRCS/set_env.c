/*
 *	Things we still need:
 *		int		env_valid(char *s);
 *		void	error(int i);
 */

void	set_env(t_env *env, char *s)
{
	char	*temp;

	if (env_valid(s))
	{
		temp = env->a;
		env->a = ft_strjoin(env->a, s);
		free(temp);
	}
	else
		error(0);
}
