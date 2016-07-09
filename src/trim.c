#include "../includes/minishell.h"

char	*trim_start(char *str)
{
	int		k;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t')
		k++;
	if (k > 0)
	{
		str = ft_strcpy(str, &str[k]);
		str[ft_strlen(str) - k] = '\0';
	}
	return (str);
}

void	trim_end(char **str)
{
	int		k;

	if (*str == NULL)
		return ;
	k = ft_strlen(*str) - 1;
	while (k >= 0 && (*str[k] == ' ' || k == '\t'))
		k--;
	if (*str[k] && *str[k + 1] && 
		(*str[k + 1] == ' ' || *str[k + 1] == '\t'))
			*str[k + 1] = '\0';
}

void	trim_str(char **str)
{
	if (*str == NULL)
		return ;
	*str = trim_start(*str);
	//trim_end(str);
}

int		trim_arr(char ***arr)
{
	int		k;

	k = 0;
	ft_putstr("before loop\n");//debug
	while (arr[0][k] != NULL)
	{
		ft_putstr("in looop\n");//debug
		trim_str(&arr[0][k]);
		ft_putstr("trimmed\n");//debug
		k++;
	}
	return (k);
}

char	*rm_tabs(char *str)
{
	int		k;

	while (str[k] != '\0')
	{
		if (str[k] == '\t')
			str[k] = ' ';
		k++;
	}
	return (str);
}
