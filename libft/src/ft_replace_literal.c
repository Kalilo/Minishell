/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace2_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:14:46 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/07 16:39:55 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_replace_literal(const char *str, char a, char b, char c)
{
	const char	*ptr;
	const char	*ptr2;
	char		*dest;
	char		type;
	size_t		len;
	size_t		cnt;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - 2));
	ptr = ft_3charcmp(str, a, b, c);
	ptr2 = ft_2charcmp(str, b, c);
	len = ft_strlen(str) - ft_strlen(ptr);
	type = ft_check_literal(a, b, c);
	if (ptr != NULL)
	{
		cnt = 0;
		while (len-- > 0)
		{
			dest[cnt] = str[cnt];
			cnt++;
		}
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
//	ft_mem_append(dest, 2);
//	dest = ft_strcpy(dest, str);
	return (dest);
}
