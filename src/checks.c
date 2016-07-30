/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:17:46 by khansman          #+#    #+#             */
/*   Updated: 2016/07/10 13:46:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	allowed_character(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (ft_memchr(AL_SYM, c, ft_strlen(AL_SYM)) != NULL)
		return (1);
	return (0);
}

int	str_valid(t_env *env, char *str)
{
	int		k;

	k = 0;
	while (str[k] != '\0')
	{
		if (!(allowed_character(str[k])))
			return (0);
		k++;
	}
	return (1);
}

int	arg_valid(char **sa, int i)
{
	int		k;

	k = 0;
	return (1);
}

int		check_line(char *line)
{
	int		check;

	check = 0;
	if (line == NULL)
		return (0);
	while (*line)
	{
		if (ft_isprint(*line) && *line != ' ' && *line != '\t')
			return (1);
		line++;
	}
	return (0);
}
