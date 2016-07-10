/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 11:52:19 by ehansman          #+#    #+#             */
/*   Updated: 2016/07/10 11:56:36 by ehansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **sa)
{
	int		i;

	i = 0;
	while (sa[i])
	{
		ft_putstr(sa[i++]);
		ft_putchar('\n');
	}
}

char	*find_var_val(t_env *env, const char *var)
{
	char	*seeked;
	int		k;

	k = 0;
	while (E_EN[k] != NULL)
	{
		if (ft_strstr(E_EN[k], var) != NULL)
		{
			seeked = ft_strchr(E_EN[k], '=');
			seeked++;
			chdir(seeked);
			return (seeked);
		}
		k++;
	}
	return (NULL);
}

void	update_env(t_env *env, char *var, char *n)
{
	char	*val;
	char	*temp;
	int		k;

	k = 0;
	while (E_EN[k] != NULL)
	{
		if (ft_strncmp(E_EN[k], var, ft_strlen(var)) == 0)
		{
			temp = ft_strjoin(var, "=");
			E_EN[k] = ft_strjoin(temp, n);
			free(temp);
		}
		k++;
	}
}
