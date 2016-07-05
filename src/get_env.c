/*
 *	Do we have a working ft_strdup??
 */

char    *add_own()
{
	char    *s; 

	s = (char *)malloc(sizeof(char) + 1); 
	s[0] = '#';
	s[1] = '\0';
	return (s);
}

char	**get_env(char **environ)
{
	int		i;
	char	**env;

	i = 0;
	while (environ[i])
		i++;
	if (!(env = (char **)malloc(sizeof(char *) * i + 2)))
	{
		ft_putstr("Memory problem.\n");
		exit(0);
	}
	i = 0;
	while (environ[i])
	{
		if (!(env[i] = (char *)malloc(sizeof(char) * ft_strlen(environ[i]))))
		{
			ft_putstr("Memory problem.\n");
			exit(0);
		}
		env[i] = environ[i];
		i++;
	}
	env[i++] = add_own();
	env[i] = NULL;
	return (env);
}
