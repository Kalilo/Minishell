#include "../includes/minishell.h"

int		scan_slash(char *str)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '\\')
			l++;
		k++;
	}
	return (l);
}

void	cd_home(t_env *env)
{
	char	*home;

	home = find_var_val(env, "HOME=");
	chdir(home);
}

void	cd_one(t_env *env, char *dir)
{
	char	*path;

	path = find_var_val(env, "PWD=");
	if (ft_strcmp(dir, "..") == 0)
		chdir(path);//need to set to remove one
	else if (scan_dir(dir, path))
	{
		path = add_path(path, dir);
		chdir(path);
		free(path);
	}
}

void	ft_cd(t_env *env, char **sa)
{
	if (sa[1] == NULL)
		cd_home(env);
	else
	{
		if (scan_slash(sa[1]) == 0 && sa[2] == NULL)
			cd_one(env, sa[1]);
	}
}
