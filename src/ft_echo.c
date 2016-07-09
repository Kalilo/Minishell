/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 10:06:53 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/09 14:56:28 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_echo(char **sa)
{
	size_t	cnt;

	cnt = 1;
	while (sa[cnt] != NULL)
	{
		ft_putstr(sa[cnt]);
		cnt++;
	}
	ft_putchar('\n');
}

void	ft_echo(char **sa)
{
	size_t	i;

	i = 1;
	while (sa[i] != NULL)
	{
//		sa[i] = ft_rmpadding(sa[i]);
		sa[i] = ft_replace_literal(sa[i]);
		i++;
	}
	ft_print_echo(sa);
}
