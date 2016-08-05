/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:17:46 by khansman          #+#    #+#             */
/*   Updated: 2016/08/02 12:03:29 by jlangman         ###   ########.fr       */
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

void	ft_help(t_env *env, char **sa)
{
	printf("\n");
	printf("\e[31mThese are the current functions you are able to use:\n");
	printf("\e[32mecho:     Displays the input string on the std output.\n");
	printf("cd:       Change the current directory to a new one.\n");
	printf("env:      view the environment.\n");
	printf("setenv:   set a new element in the environment.\n");
	printf("unsetenv: unset an element in the environment.\n");
	printf("help:     displays all available commands.\n");
	printf("exit:     end the program.\n");
}
