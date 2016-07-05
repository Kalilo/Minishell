/*
 *	Things we still need:
 *		t_env	struct
 *		int		arg_valid(char **sa, int i);
 *		int		count(char *s, char c); #plus one here to get right amount#
 *		void	error(int i);
 *		char	*find_path(char *s);
 *		int		is_own(char *s);
 *		void	own_command(char **sa);
 */

/*
 *	Which "wait" do we want to use??
 *	We need to free str in do_command().
 */

int 	do_command(char *com)
{
	char *str;
	char **arr;

	arr = ft_strsplit(com, ' ');
	str = ft_strjoin("/bin/", arr[0]);
	execve(str, arr, NULL);
}

void	do_fork(char *s)
{
	pid_t	forked;

	forked = fork();
	if (forked == 0)
		do_command(s);
	wait(0);
}

void	command(t_env *env, char *s)
{
	char	**sa;
	char	*exe;

	if (ft_strlen(s) == 0)
		return ;
	sa = ft_strsplit(s, ' ');
	if	(arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(sa);
		else
		{
			exe = find_path(sa[0]);
			if (exe[0] != '\0')
			{
				do_fork(exe);// Double check the do_fork()
				free(exe);//Will this work or does prog that we busy with terminate?? Read 2de colom 2de comment
			}
			else
				error(2);
		}
	}
	else
		error(1);
}//24 lines
