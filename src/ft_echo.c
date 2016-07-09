/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 10:06:53 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/09 13:35:41 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **sa)
{
	size_t	i;

	i = 0;
	while (sa[i] != NULL && sa[i])
	{
		sa[i] = ft_rmpadding(sa[i]);
		sa[i] = ft_replace_literal(sa[i]);
		i++;
	}
	ft_env(sa);
}
