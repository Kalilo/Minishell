#include "../includes/minishell.h"


/*
**	Adds a char to the beginning of a string
*/
void	ft_add_char_start(char **str, char c)
{
	char	*s;
	int		k;

	if (!str || !*str)
		return ;
	s = (char *)ft_strnew(ft_strlen(*str) + 2);
	k = -1;
	*s = c;
	while (*str[++k])
		s[k + 1] = *str[k];
	free(*str);
	*str = s;
}

/*
**	Adds a char to the end of a string
*/
void	ft_add_char_end(char **str, char c)
{
	int		k;
	char	*s;

	if (!str || !*str)
		return ;
	s = (char *)ft_strnew(ft_strlen(*str) + 2);
	k = -1;
	while (*str[++k])
		s[k] = *str[k];
	s[++k] = c;
	free(*str);
	*str = s;
}

void	ke_left(t_env *env)
{
	int		k;

	if (I_L1 == NULL)
		return ;
	k = ft_strlen(I_L1) - 1;
	if (k < 0)
		return ;
	ft_add_char_start(&I_L2, I_L1[k]);
	I_L1[k] = '\0';
	I_C1 = k - 1;
	I_C2 = ft_strlen(I_L2);
}

void	ke_right(t_env *env)
{
	char	*k;

	if (I_L2 == NULL || *I_L2 == 0)
		return ;
	k = ft_strdup((I_L2 + 1));
	ft_add_char_end(&I_L1, + 1);
	I_C1 = ft_strlen(I_L1);
	I_C2 = ft_strlen(I_L2);
	free(I_L2);
	I_L2 = k;
}
