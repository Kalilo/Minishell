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
		str = ft_strjoin(find_path(env, arr[0]), arr[0]);
		execve(str, arr, E_EN);
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
	s = rm_tabs(s);
	sa = ft_strsplit(s, ' ');
	ft_env(sa);
	if	(arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(env, sa, s);
		else
		{
			do_command(env, s);
		}
	}
	else
		error(1);
	free2d(sa);
}
