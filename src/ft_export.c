#include "../includes/minishell.h"

void	ft_export(char *sa[], int env_size, char *s)
{
	char	*temp;
	char	*temp2;

	temp = sa[env_size - 1];
	temp2 = NULL;
	if (ft_strcmp(sa[env_size - 1], "#") == 0)
		sa[env_size - 1] = s;
	else
	{
		sa[env_size - 1] = ft_strjoin(sa[env_size - 1], "\n");
		temp2 = sa[env_size - 1];
		sa[env_size - 1] = ft_strjoin(sa[env_size - 1], s);
	}
	free (temp);
	if (temp2)
		free(temp2);
}
