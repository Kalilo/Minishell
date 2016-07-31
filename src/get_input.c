/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:24:49 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:25:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_key(t_env *env)
{
	char	key[4];

	key[0] = I_TMP;
	if (I_TMP == '\e')
	{
		read(1, &key[1], 1);
		read(1, &key[2], 1);
	}
	key[3] = '\0';
	//Continue here...
}

void	print_line(char *line)
{
	int		l;

	l = -1;
	ft_putchar('\r');
	ft_putstr(SH_L);
	while (line[++l])
		ft_putchar(line[l]);
}

int		get_input(t_env *env, int fd, char **line)
{
	I_TMP = 23;
	I_L1 = NULL;
	I_C1 = -1;
	while (I_TMP != '\r' && I_TMP != '\n' && I_TMP != '\0')
	{
		read(fd, &I_TMP, 1);
		if (I_C1 + 2 % 50 == 0 || I_C1 == -1)
			I_L1 = re_malloc(I_L1, I_C1 + 1);
		if (!ft_isprint(I_TMP) && I_TMP != '\0' && I_TMP != '\r'
				&& I_TMP != '\n')
			get_key(env);
		else
			I_L1[++I_C1] = I_TMP;
		print_line(I_L1);
	}
	if (I_C1 + 1)
		I_L1[I_C1] = 0;
	*line = I_L1;
	if (++I_C1)
		return (1);
	return (0);
}
