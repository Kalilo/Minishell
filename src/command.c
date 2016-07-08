#include "../includes/minishell.h"

int 	do_command(t_env *env, char *com)
{
	char	*str;
	char	**arr;
	pid_t	forked;

	forked = fork();
	if (forked == 0)
	{
		arr = ft_strsplit(com, ' ');
		str = ft_strjoin("/bin/", arr[0]);//debug
		execve(str, arr, NULL);
		exit(0);
	}
	else
		wait(0);
	return (1);
}

void	command(t_env *env, char *s)
{
	char	**sa;

	if (s == NULL)
		return ;
	sa = ft_strsplit(s, ' ');
	if	(arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(sa);
		else
		{
			do_command(env, s);
			//free(com); //Will this work or does prog that we busy with terminate?? Read 2de colom 2de comment
		}
	}
	else
		error(1);
}//24 lines
