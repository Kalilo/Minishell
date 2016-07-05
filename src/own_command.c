#include "../includes/minishell.h"

int is_own(char *s)
{ 
	int		k;
	
	k = ft_strlen(s);
	if (!(k) || ft_strstr(OWN_FUNCS, s, k) != NULL)
		return (1);
	return (0);
}
