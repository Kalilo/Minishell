/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:50:03 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/06/20 07:46:31 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*cpy;
	char	*cpy2;

	cpy = (char *)big;
	cpy2 = (char *)little;
	if (little == NULL)
		return ((char *)big);
	while (cpy)
	{
		if (*cpy2 == *cpy)
			cpy2++;
		else
			cpy2 = (char *)little;
		if (*cpy2 == '\0')
			return (cpy - ft_strlen(little) + 1);
		cpy++;
	}
	return (NULL);
}
