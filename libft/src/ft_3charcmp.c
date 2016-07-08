/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3charcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 15:44:34 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/07/07 16:39:59 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

const char	*ft_3charcmp(const char *str, char a, char b, char c)
{
	size_t	cnt;
	const char	*ptr;

	cnt = 0;
	ptr = str;
	while (ptr && *ptr != '\0' && (ptr + 1) && \
			*(ptr + 1) != '\0' && (ptr + 2) && *(ptr + 2) != '\0')
	{
		if (*ptr == a && *(ptr + 1) == b && *(ptr + 2) == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
