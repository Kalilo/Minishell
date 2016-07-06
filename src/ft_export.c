#include "../includes/minishell.h"

void	ft_export(char *sa[], int env_size, char *s)
{
	char	*temp;
	char	*stemp;

	temp = sa[env_size - 1];
	stemp = s;
	s = ft_strjoin(s, "\n");
	if (ft_strcmp(sa[env_size - 1], "#") == 0)
		sa[env_size - 1] = s;
	else
		sa[env_size - 1] = ft_strjoin(sa[env_size], s);
	free (temp);
	free(stemp);
}
