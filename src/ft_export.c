/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:22:37 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:32:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unsetenv(t_env *env, char **sa)
{
	int		k;
	
	k = 0;
	if (sa[0] == NULL || sa[1] == NULL)
		return ;
	while (E_EN[k] != NULL && 
		ft_strncmp(E_EN[k], sa[1], ft_strlen(sa[1])) != 0)
			k++;
	if (k < E_SI)
	{
		ft_putstr(E_MESS08);
		return ;
	}
	if (E_EN[k] != NULL &&
		ft_strncmp(E_EN[k], sa[1], ft_strlen(sa[1])) == 0)
	{
		free(E_EN[k]);
		while (E_EN[k + 1] != NULL)
		{
			E_EN[k] = E_EN[k + 1];
			k++;
		}
		E_EN[k] = NULL;
	}
	ERROR_6;
}

char	*ft_remove_parenthesis(char *str)
{
	int		k;

	k = 0;
	if (str == NULL)
		return (NULL);
	while (str[k] != '\"' && str[k] != '\'')
		k++;
	if (str[k] == '\"' || str[k] == '\'')
		str = &str[k];
	k = 0;
	while (str[k] != '\"' && str[k] != '\'')
		k++;
	if (str[k] == '\"' || str[k] == '\'')
		str[k] = '\0';
	return (str);
}

void	ft_setenv(t_env *env, char **sa)
{
	int		k;

	if (ft_strchr(sa[1], '=') == NULL)
	{
		ft_putstr(E_MESS09);
		return ;
	}
	k = 0;
	while (E_EN[k] != NULL)
		k++;
	if (k > 100)
	{
		ft_putstr(E_MESS07);
		return ;
	}
	else
		E_EN[k] = ft_strdup(sa[1]);
}

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
	free(temp);
	if (temp2)
		free(temp2);
}
