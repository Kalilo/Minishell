#include "../includes/minishell.h"

int		main()
{
	t_env	env;
	char	*line;
	extern char **environ;

	env.environ = get_env(environ);
	line = NULL;
	while (1)
	{
		ft_putstr(SH_L);
		get_line(0, &line);
		if (ft_memcmp(line, CM_EXIT, CM_EXIT_S) == 0)
			break;
		if (ft_strchr_f(line, '=') != 0)
			set_env(&env, line);
		else
			command(&env, line);
		free(line);
	}
	//free(env.exe);//this is also a possible solution for that string we need to free.
	//(We can make this list bigger once we struggle to free something and then create a function)
	exit(1);
}
