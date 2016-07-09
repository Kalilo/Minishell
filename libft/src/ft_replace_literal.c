/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_literal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:14:46 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/09 14:19:41 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_replace_literal(char *str)
{
	size_t		len;
	size_t		cnt;
	char		*ptr;
	char		*dest;
	char		type;
	char		a;
	char		b;

	a = '\\';
	b = '\\';
	ptr = NULL;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - 2));
	ptr = ft_2charcmp(str, a, b);
	len = ft_strlen(str) - ft_strlen(ptr);
	if (ptr != NULL)
	{
		cnt = 0;
		while (len-- > 0)
		{
			dest[cnt] = str[cnt];
			cnt++;
		}
		if ((type = ft_check_literal(str[cnt], str[cnt + 1], \
						str[cnt + 2])) != 32)
		{
			dest[cnt] = type;
			cnt++;
			while (str[cnt + 2] && str[cnt + 2] != '\0')
			{
				dest[cnt] = str[cnt + 2];
				cnt++;
			}
			dest[cnt] = '\0';
			return (dest);
		}
		else
		{
			dest[cnt] = '\\';
			cnt++;
			while (str[cnt + 1] && str[cnt + 1] != '\0')
			{
				dest[cnt] = str[cnt + 1];
				cnt++;
			}
			dest[cnt] = '\0';
			return (dest);
		}
	}
	return (str);
}
