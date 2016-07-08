/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_literal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:28:08 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/07 16:20:56 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	ft_check_literal(char a, char b, char c)
{
	if (a == 92 && b == 92)
	{
		if (c == 't')
			return ('\t');
		if (c == 39)
			return ('\'');
		if (c == 34)
			return ('\"');
		if (c == 92)
			return ('\\');
		if (c == '0')
			return ('\0');
		if (c == 'a')
			return ('\a');
		if (c == 'b')
			return ('\b');
		if (c == 'f')
			return ('\f');
		if (c == 'n')
			return ('\n');
		if (c == 'r')
			return ('\r');
		if (c == 'v')
			return ('\v');
	}
	return (0);
}
