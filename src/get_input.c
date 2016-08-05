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
	char		key[10];
	int			k;

	k = 0;
	key[k] = I_TMP;
	if (I_TMP == '\e')
	{
		read(1, &key[++k], 1);
		read(1, &key[++k], 1);
		if ('1' <= key[k] && key[k] <= '3')
		{
			read(1, &key[++k], 1);
			if (key[k] != '~')
				read(1, &key[++k], 1);
		}
	}
	key[++k] = '\0';
	key_handler(env, key);
	return ;
}

void	print_line(char *line, char * line2)
{
	static int	k;
	int			l;

	l = -1;
	ft_putchar('\r');
	while (++l < k)
		ft_putchar(' ');
	l = (ft_strlen(line) >= ft_termsize(0) - 4) ?
		ft_strlen(line) + 5 - ft_termsize(0) : -1;
	ft_putstr(SH_L);
	while (line[++l])
		if (*line != '\n' && *line != '\v')
			ft_putchar(line[l]);
	k = l + 3;
	l = -1;
	while (line2 && line2[++l])
		ft_putchar(line2[l]);
	k += l + 1;
	while (l-- > 0)
		ft_putchar('\b');
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
		print_line(I_L1, I_L2);
	}
	if (I_C1 + 1)
		I_L1[I_C1] = 0;
	*line = ft_strjoin(I_L1, I_L2);
	if (++I_C1)
		return (1);
	return (0);
}
