#include "../includes/minishell.h"

#include <string.h>

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
	char			**str;
	
	k = 0;
	printf("finding path, s = %s\n", s);//debug
	if (s == NULL)
		return (NULL);
	while (E_EN[k] != NULL)
	{
		
		if (ft_strstr(E_EN[k], "PATH=") != NULL)
		{
			printf("path found, PATH = %s\n", E_EN[k]);//debug
			s = ft_strchr(s, '=');
			s++;
			printf("%s\n", s);//debug
			
		}
		k++;
	}
	return (NULL);
}
