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

void	get_key(char *l)
{
	char	key[4];

	read(1, &key[0], 1);
	read(1, &key[1], 1);
	key[2] = '\0';
	
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

int		get_input(int fd, char **line)
{
	int		k;
	char	*l;
	char	buff;

	buff = 23;
	l = NULL;
	k = -1;
	while (buff != '\r' && buff != '\n' && buff != '\0')
	{
		read(fd, &buff, 1);
		if (k + 2 % 50 == 0 || k == -1)
			l = re_malloc(l, k + 1);
		if (buff == '\e')
			get_key(l);
		else
			l[++k] = buff;
		print_line(l);
	}
	if (k + 1)
		l[k] = 0;
	*line = l;
	if (++k)
		return (1);
	return (0);
}
