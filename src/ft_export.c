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

void	ft_unsetenv(t_env env, char *sa)
{
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
