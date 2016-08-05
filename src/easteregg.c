/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:13:49 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/04 11:46:25 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	easteregg(t_env *env, char **sa)
{
	FILE	*fp;
	FILE	*fopen();
	int		i;

	fp = fopen("db.txt", "r");
	while (i != EOF)
	{
		ft_putchar(i);
		i = getc(fp);
	}
	fclose(fp);
}
