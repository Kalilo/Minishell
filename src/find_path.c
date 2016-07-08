#include "../includes/minishell.h"

int		scan_dir(char *s, char *path)
{
	DIR				*dir;
	struct dirent	*file;
	
	dir = opendir(path);
	while ((file = readdir(dir)) != NULL)
	{
		if (ft_strcmp(file->d_name, s) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

char	*find_path(t_env *env, char *s)
{
	int				k;
	int				l;
	char			*p;
	char			**str;
	
	k = 0;
	l = -1;
	//printf("finding path, s = %s\n", s);//debug
	if (s == NULL)
		return (NULL);
	while (E_EN[k] != NULL)
	{
		
		if (ft_strstr(E_EN[k], "PATH=") != NULL)//need to use ft_strstr
		{
			//printf("path found, PATH = %s\n", E_EN[k]);//debug
			p = ft_strchr(E_EN[k], '=');
			p++;
			str = ft_strsplit(p, ':');
			//ft_env(str);//debug
			//printf("%s\n", s);//debug
			while (str[++l] != NULL)
				if (scan_dir(s, str[l]))
					return (ft_strjoin(str[l], "/"));			
		}
		k++;
	}
	return (NULL);
}
