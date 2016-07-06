#include "../includes/minishell.h"

int 	do_command(char *com)
{
	char	*str;
	char	**arr;
	pid_t	forked;

	forked = fork();
	if (forked == 0)
	{
		arr = ft_strsplit(com, ' ');
		//str = ft_strjoin(path, arr[0]);
		execve(arr[0], arr, NULL);
		kill(forked, 9);
	}
	else
		wait(0);
	return (1);
}

void	command(t_env *env, char *s)
{
	char	**sa;
	char	*com;

	if (ft_strlen(s) == 0)
		return ;
	sa = ft_strsplit(s, ' ');
	if	(arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(sa);
		else
		{
			//com = find_path(sa[0]);
			if (com[0] != '\0')
			{
				do_command(com); // Double check the do_fork()
				free(com); //Will this work or does prog that we busy with terminate?? Read 2de colom 2de comment
			}
			else
				error(2);
		}
	}
	else
		error(1);
}//24 lines
