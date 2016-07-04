/*
 *	Things we still need:
 *		void	get_env(t_env *env);
 *
 *		We need to modify ft_strchr to it only checks first word
 *		int		ft_strchr_f(char *s, char c);
 *		Double check everthing before we go on..
 */

int		main()
{
	t_env	env;
	char	*line;
	int		k;

	get_env(&env);
	line == NULL;
	while (1)
	{
		write(1, "$>", 2);
		get_next_line();//What are the param's?
		if (memcmp(line, exit, k ) == 0)
			break;
		if (ft_strchr_f(line, '=') != NULL)
			set_env(&env, line);
		else
			command(&env, line);
		k++;
	}
	free(env.exe);//this is also a possible solution for that string we need to free.
	//(We can make this list bigger once we struggle to free something and then create a function)
	exit(1);
}
